// RAII全称是Resource Acquisition Is Initialization，直译过来就是：资源获取即初始化。
// RAII是一种C++编程技术，它将必须在使用前请求的资源（例如：分配的堆内存、执行线程、打开的套接字、打开的文件、锁定的互斥体、磁盘空间、数据库连接等——任何存在受限供给中的事物）的生命周期与一个对象的生存周期相绑定。
// RAII保证资源可用于任何会访问该对象的函数。它亦保证所有资源在其控制对象的生存期结束时，以获取顺序的逆序释放。类似地，若资源获取失败（构造函数以异常退出），则为已构造完成的对象和基类子对象所获取的所有资源，会以初始化顺序的逆序释放。这有效地利用了语言特性以消除内存泄漏并保证异常安全。

#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <condition_variable>
#include <set>


class Account {
public:
    Account(std::string name, double money) : name_(name), money_(money) {};

    void ChangeMoney(double amount) {
        std::unique_lock<std::mutex> lock(money_lock_);
        // 阻塞当前线程直至条件满足
        condition_var_.wait(lock, [this, amount] {
            return money_ + amount > 0;
        });
        money_ += amount;
        condition_var_.notify_all();
    }

    std::string GetName() {
        return name_;
    }

    double GetMoney() {
        return money_;
    }

private:
    std::string name_;
    double money_;
    std::mutex money_lock_;
    std::condition_variable condition_var_; // 声明一个条件变量
};

class Bank {
public:
    void AddAccount(Account* account) {
        accounts_.insert(account);
    }

    void TransferMoney(Account* account_a, Account* account_b, double amount) {
        /**把a的钱转给b */
        account_a->ChangeMoney(-amount);
        account_b->ChangeMoney(amount);
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

std::mutex cout_lock; // 控制打印的锁

void RandomTransfer(Bank* bank, Account* account_a, Account* account_b) {
    while (true) {
        double random_money = ((double)rand() / RAND_MAX) * 100;
        {
            // 花括号限定锁的生命周期
            // 将cout的资源的申请与释放和guard的生命周期绑定在了一起
            std::lock_guard<std::mutex> guard(cout_lock);
            std::cout << "Transfer " << random_money 
                        << " from " << account_a->GetName()
                        << "(" << account_a->GetMoney()
                        << ") to " << account_b->GetName()
                        << "(" << account_b->GetMoney()
                        << "), Bank TotalMoney: " << bank->TotalMoney() << std::endl;
        }
        bank->TransferMoney(account_a, account_b, random_money);
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