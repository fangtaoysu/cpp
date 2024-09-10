#include <iostream>
// 管理线程的类的函数
#include <thread>


void Hello() {
    std::cout << "hello" << std::endl;
}

int main() {
    std::thread t(Hello);
    t.join();

    return 0;
}