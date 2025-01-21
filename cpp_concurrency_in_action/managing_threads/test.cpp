/** 
    1. std::thread对象在声明的时候就已经处于运行状态了（未连接状态：未和主线程建立连接），join和detach则是负责管理线程的生命周期以及新线程与主线程的关系
        - join: join管理新线程的生命周期
        - detach: 操作系统管理新线程的生命周期
    2. 如果thread对象在生命周期结束前还未声明线程管理方式（join/detach），新线程将变成“野线程”，失去了控制权和管理
    3. 如果想让程序在该线程的后台运行，需要确保不会向函数中传入局部变量的指针或引用（声明周期不一致）
    4. 

 */
#include <exception>
#include <iostream>
// 管理线程的类的函数
#include <stdexcept>
#include <thread>
#include <memory>
#include <chrono>


void PrintI(unsigned i) {
    std::cout << i << std::endl;
}
struct Func {
    int& data_;
    explicit Func(int& data) : data_(data) {}
    void operator() () {
        try {
            for (int i = 0; i < 5; ++i) {
                std::cout << "Thread accessing data: " << data_ << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
            }
        } catch (const std::exception& e) {
            std::cout << "Exception caught in thread:" << e.what() << std::endl;
        }
    }
};

int DoSomethingInCurrentThread() {
    int val = 0;
    if (val == 0) {
        throw std::runtime_error("Division by zero is not allowed");
    }
    return 3 / val;
}

void TestJoin() {
    auto some_local_state = std::make_shared<int>(15);
    Func my_func(*some_local_state);
    std::thread t(my_func);
    try {
        DoSomethingInCurrentThread();
    } catch (const std::exception& e) {
        if (t.joinable()) {
            std::cout << "join run" << std::endl;
            t.join();
        }
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    if (t.joinable()) {
        t.join();
    }
}

class ThreadGuard {
    std::thread& t_;
public:
    explicit ThreadGuard(std::thread& t) : t_(t) {}
    ~ThreadGuard() {
        if (t_.joinable()) {
            t_.join();
        }
    }
    ThreadGuard(ThreadGuard const &)=delete; // 不自动生成默认的构造拷贝函数
    ThreadGuard& operator=(ThreadGuard const&)=delete; // 不自动生成默认的操作拷贝运算符
};


int main() {
    TestJoin();
    return 0;
}