/** async 是由系统管理的，启动即执行
    适用场景:
        - 简单的并行任务
        - 指定任务的执行策略（同步/异步）
        - 自动调度，无需显示管理线程
 */
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

void LambdaWoker() {
    double result = 0;
    std::cout << "Async task with lambda triggered, thread: " << std::this_thread::get_id() << std::endl;
    // std::launch::async声明异步执行；deferred声明同步执行
    auto f2 = std::async(std::launch::async, [&result]() {
        std::cout << "Lambda task in thread: " << std::this_thread::get_id() << std::endl;
        for (int i = 0; i <= MAX; ++i) {
            result += sqrt(i);
        }
    });
    f2.wait();
    std::cout << "Async task with lambda finish, result: " << result << std::endl;
}

class ClassWorker {
public:
    ClassWorker(int min, int max) : min_(min), max_(max) {};

    double Work() {
        result_ = 0;
        for (int i = min_; i <= max_; ++i) {
            result_ += sqrt(i);
        }
        return result_;
    }

    double GetResult() {
        return result_;
    }

private:
    int min_;
    int max_;
    double result_;
};

int main() {
    sum = 0;
    // 返回future对象，存储异步执行结果
    auto f1 = std::async(Worker, 0, MAX);
    std::cout << "Async task triggered" << std::endl;
    f1.wait();
    std::cout << "Async task finish, result: " << sum << std::endl;
    // TODO https://zhuanlan.zhihu.com/p/340278634
    LambdaWoker();
    ClassWorker worker3(0, MAX);
    auto f3 = std::async(&ClassWorker::Work, &worker3);
    f3.wait();
    std::cout << "Task in class finish, resultL " << worker3.GetResult() << std::endl;
    
    return 0;
}