/*
 * @Date: 2024-09-10 10:03:27
 * @LastEditTime: 2024-09-26 17:50:21
 * @FilePath: /cpp/cpp_concurrency_in_action/managing_threads/main.cpp
 * @Description: 
 * 
 * @Author: fangtao
 * Copyright (c) 2024 by fangtao, All Rights Reserved. 
 */
#include <iostream>
// 管理线程的类的函数
#include <thread>
#include <memory>


void PrintI(unsigned i) {
    std::cout << i << std::endl;
}
struct Func {
    int& i_;
    Func(int& i) : i_(i) {}
    void operator() () {
        std::cout << "start" << std::endl;
        for (unsigned j = 0; j < 10000; ++j) {
            PrintI(i_+j);
        }
        std::cout << "end" << std::endl;
    }
};

void TestlocalDetach() {
    /**如果想让程序在该线程的后台运行，需要确保不会向函数中传入局部变量的指针或引用
        例：传入局部变量的指针后，线程执行的函数在当前函数退出时结束
    */
    // 传入引用或指针使用 make_shared管理
    auto some_local_state = std::make_shared<int>(0);
    // unsigned some_local_state = 0;
    Func my_func(*some_local_state);
    std::thread my_thread(my_func); // 开始执行线程my_thread
    // detach 和 join 配置的是新的线程和当前线程的关系
    my_thread.detach(); // 新线程和当前线程分离
    // my_thread.join(); // 当前线程（被阻塞）会等待新线程结束
}

int DoSomethingInCurrentThread() {
    int val = 1;
    return 3 / val;
}

void TestJoin() {
    auto some_local_state = std::make_shared<int>(0);
    Func my_func(*some_local_state);
    std::thread t(my_func);
    try {
        DoSomethingInCurrentThread();
    } catch (...) {
        t.join();
        throw;
    }
    t.join();
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
    // TestJoin();
    // TestRAII();
    return 0;
}