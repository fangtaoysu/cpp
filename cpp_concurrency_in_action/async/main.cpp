#include <cmath>
#include <future>
#include <iostream>
#include <ostream>
#include <thread>
#include <cmath>


static const int MAX = 10e8;
static double sum = 0;

void Worker(int min, int max) {
    for (int i = min; i <= max; ++i) {
        sum += std::sqrt(i);
    }
}

int main() {
    sum = 0;
    // 返回future对象，存储异步执行结果
    auto f1 = std::async(Worker, 0, MAX);
    std::cout << "Async task triggered" << std::endl;
    f1.wait();
    std::cout << "Async task finish, result: " << sum << std::endl;
    // TODO https://zhuanlan.zhihu.com/p/340278634
}