#include <iostream>
#include <list>
#include <mutex>
#include <thread>
#include <algorithm>

std::list<int> some_list;
std::mutex some_mutex;

// 手动lock/unlock版本
void add_to_list_manual(int new_value) {
    some_mutex.lock();                    // 手动加锁
    try {
        some_list.push_back(new_value);
        some_mutex.unlock();              // 手动解锁
    } catch (...) {
        some_mutex.unlock();              // 异常时也必须解锁！
        throw;
    }
}

// 等效的lock_guard版本
void add_to_list_raii(int new_value) {
    std::lock_guard<std::mutex> guard(some_mutex);  // 自动管理
    some_list.push_back(new_value);
}   // 自动解锁


void check_lock_status() {
    if (some_mutex.try_lock()) {
        std::cout << "Mutex was UNLOCKED, now locked successfully" << std::endl;
        some_mutex.unlock();  // 立即解锁
    } else {
        std::cout << "Mutex is currently LOCKED" << std::endl;
    }
}

void test_lock_status() {
    std::cout << "Initial status: ";
    check_lock_status();  // 应该显示UNLOCKED
    
    {
        std::lock_guard<std::mutex> guard(some_mutex);
        std::cout << "Inside lock_guard scope: ";
        check_lock_status();  // 应该显示LOCKED
    }
    
    std::cout << "After lock_guard scope: ";
    check_lock_status();  // 应该显示UNLOCKED
}


int main() {
    std::thread t1(add_to_list_manual, 42);
    std::thread t2(add_to_list_raii, 43);
    t1.join();
    t2.join();
    
    test_lock_status();
    // 输出列表内容以验证
    for (int value : some_list) {
        std::cout << value << std::endl;
    }

    return 0;
}