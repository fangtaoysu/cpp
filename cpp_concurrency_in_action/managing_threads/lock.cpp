#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <set>


class Account {
public:
    Account(std::string name, double money) : name_(name), money_(money) {};
    void ChangeMoney(double amout) {
        money_ += amout;
    }
    std::string GetName() {
        return name_;
    }
    double GetMoney() {
        return money_;
    }
    std::mutex* GetLock() {
        return &money_lock_;
    }

private:
    std::string name_;
    double money_;
    std::mutex money_lock_;
};

class Bank {
public:
    void AddAccount(Account* account) {
        accounts_.insert(account);
    }

    bool TransferMoney(Account* account_a, Account* account_b, double amount) {
        /**把a的钱转给b */
        // lock_guard 简单的管理单把锁的声明周期
        // std::lock(*account_a->GetLock(), *account_b->GetLock());
        // // lock_guard 构造时加锁，析构时解锁，只有一个构造函数；适用于一把锁的场景
        // // 使用lock_guard只能管理一把锁，在需要多个锁的场景，可能发生死锁，需要使用lock来管理锁
        // // 在使用lock之后，还需要使用adopt_lock声明锁对象已经被其他机制锁定，否则就会重复上锁
        // std::lock_guard guard_a(*account_a->GetLock(), std::adopt_lock);
        // std::lock_guard guard_b(*account_b->GetLock(), std::adopt_lock);

        // // 等价写法1：
        // unique_lock 灵活的管理单把锁的生命周期
        // unique_lock 不直接支持管理多把锁，可以使用lock手动锁定多个锁，然后使用unique_lock接管这些锁
        std::lock(*account_a->GetLock(), *account_b->GetLock());
        std::unique_lock<std::mutex> lock_a(*account_a->GetLock(), std::adopt_lock);
        std::unique_lock<std::mutex> lock_b(*account_b->GetLock(), std::adopt_lock);
        // // 等价写法2：
        // // scoped_lock 多把锁的锁管理器
        // std::scoped_lock(*account_a->GetLock(), *account_b->GetLock());

        if (amount > account_a->GetMoney()) {
            return false;
        }

        account_a->ChangeMoney(-amount);
        account_b->ChangeMoney(amount);
        return true;
    }

    double TotalMoney() const {
        double sum = 0;
        for (auto a : accounts_) {
            sum += a->GetMoney();
        }
        return sum;
    }

private:
    std::set<Account*> accounts_;
};

// 此版本会死锁
// void RandomTransfer(Bank* bank, Account* account_a, Account* account_b) {
//     /**随机转账 */
//     while (true) {
//         // (double)rand() / RAND_MAX 生成0-1之间的小数
//         double random_money = ((double)rand() / RAND_MAX) * 100;
//         if (bank->TransferMoney(account_a, account_b, random_money)) {
//             std::cout << "Transfer " << random_money 
//                        << " from " << account_a->GetName()
//                        << " to " << account_b->GetName()
//                        << ", Bank TotalMoney: " << bank->TotalMoney() << std::endl;
//         } else {
//             std::cout << "Transfer failed, " << account_a->GetName()
//                       << " Has only " << account_a->GetMoney()
//                       << "￥, but " << random_money << " required.\n";
//         }
//     }
// }

std::mutex cout_lock; // 控制打印的锁

void RandomTransfer(Bank* bank, Account* account_a, Account* account_b) {
    while (true) {
        double random_money = ((double)rand() / RAND_MAX) * 100;
        if (bank->TransferMoney(account_a, account_b, random_money)) {
            cout_lock.lock();
            std::cout << "Transfer " << random_money 
                       << " from " << account_a->GetName()
                       << " to " << account_b->GetName()
                       << ", Bank TotalMoney: " << bank->TotalMoney() << std::endl;
            cout_lock.unlock();
        } else {
            cout_lock.lock();
            std::cout << "Transfer failed, " << account_a->GetName()
                      << " Has only " << account_a->GetMoney()
                      << "￥, but " << random_money << " required.\n";
            cout_lock.unlock();
        }
    }
}

int main() {
    Account people_a("alias", 100);
    Account people_b("lily", 100);
    Bank bank;
    bank.AddAccount(&people_a);
    bank.AddAccount(&people_b);

    std::thread t1(RandomTransfer, &bank, &people_a, &people_b);
    std::thread t2(RandomTransfer, &bank, &people_b, &people_a);

    t1.join();
    t2.join();


    return 0;
}