/** 
    1. std::thread对象在声明的时候就已经处于运行状态了（未连接状态：未和主线程建立连接），join和detach则是负责管理线程的生命周期以及新线程与主线程的关系
        - join: join管理新线程的生命周期；主线程暂停执行直到子线程执行结束
        - detach: 操作系统管理新线程的生命周期；
    2. 如果thread对象在生命周期结束前还未声明线程管理方式（join/detach），新线程将变成“野线程”，失去了控制权和管理
    3. 如果想让程序在该线程的后台运行，需要确保不会向函数中传入局部变量的指针或引用（声明周期不一致）
    4. 

 */
#include <cstdio>
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

void TestLocalVariable1() {
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
        // 保证join只执行一次
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
    // 不提供拷贝构造函数和拷贝复制运算符，保证资源不共享，防止反复释放同一资源
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
    try {
        DoSomethingInCurrentThread();
    } catch (const std::exception& e) {
        std::cout << "catch a error in DoSomethingCurrentThread" << std::endl;
    }
}


void PrintParameter(int i, const std::string& str) {
    for (int i = 0; i < 5; ++i) {
        std::cout << "Print Parameter: " 
                << i << ", "
                << str << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

void CallThread(const std::string& str) {
    std::thread t1(PrintParameter, 6, str);
    if (t1.joinable()) {
        t1.detach();
    }
}

void Func() {
    std::string str = "abc";
    CallThread(std::ref(str));
}

void TestPassingParameter() {
    Func();
    // 此时Func函数中的变量str已经被销毁，但是线程t仍然能正常运行
    std::cout << "Main thread exiting, destroying str..." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
}

void TestLocalVariable2() {
    char buff[1024];
    sprintf(buff, "%i", 10);
    // buff是局部变量，在程序运行结束后会销毁，因此线程t运行一半就退出了
    // 如果使用string类型，string的生命周期与对象绑定，因此不会出现这种情况
    std::thread t2(PrintParameter, 6, buff);
    // std::thread t2(PrintParameter, 6, std::string(buff));
    if (t2.joinable()) {
        t2.detach();
    }
}

int main() {
    // TestLocalVariable1();
    // TestLocalVariable2();
    // TestJoin();
    // TestRAII();
    TestPassingParameter();
    return 0;
}