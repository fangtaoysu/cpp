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
        for (int i = 0; i < 5; ++i) {
            std::cout << "Thread accessing data: " << data_ << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    }
};

void TestlocalVariable() {
    /**如果想让程序在该线程的后台运行，需要确保不会向函数中传入局部变量的指针或引用
        原因：线程读取了无效的内存地址
        例：传入指针时，使用join可以正常运行，但是detach不行
    */
    // 传入引用或指针使用 make_shared管理
    auto some_local_state = std::make_shared<int>(0);
    // unsigned some_local_state = 0;
    Func my_func(*some_local_state);
    std::thread my_thread(my_func); // 开始执行线程my_thread
    // detach 和 join 配置的是新的线程和当前线程的关系
    my_thread.detach();
    // my_thread.join();
}

int DoSomethingInCurrentThread() {
    try {
        int val = 0;
        return 3 / val;
    } catch (...) {
        throw std::runtime_error("0 cannot be used as a divisor");
    }
    return 0;
}

void TestJoin() {
    auto some_local_state = std::make_shared<int>(15);
    Func my_func(*some_local_state);
    std::thread t(my_func);
    try {
        DoSomethingInCurrentThread();
        // throw std::runtime_error("Simulated exception in main thread");
    } catch (const std::exception& e) {
        if (t.joinable()) {
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

void TestRAII() {
    /** RAII: Resource Acquisition Is Initialization
        当调用函数中需要传递局部变量的引用或指针时，可能出现局部变量销毁后才执行线程对应函数；
        因此使用RAII来管理
    */
    auto some_local_state = std::make_shared<int>(0);
    Func my_func(*some_local_state);
    std::thread t(my_func);
    ThreadGuard g(t);
    DoSomethingInCurrentThread();
}


int main() {
    // TestlocalDetach();
    TestJoin();
    // TestRAII();
    return 0;
}