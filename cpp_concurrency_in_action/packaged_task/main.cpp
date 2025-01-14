/** packaged_task 将可调用对象封装为一个异步任务
    适用场景：
     - 任务队列
     - 线程池
 */
#include <chrono>
#include <cmath>
#include <future>
#include <iostream>
#include <thread>
#include <vector>
#include <chrono>


static const int MAX = 10e8;

double ConcurrentWorker(int min, int max) {
    double sum = 0;
    for (int i = min; i <= max; ++i) {
        sum += std::sqrt(i);
    }
    return sum;
}

void ConcurrentTask(int min, int max, std::promise<double>* result) {
    // 接收任务结果
    std::vector<std::future<double>> results;
    unsigned concurrent_count = std::thread::hardware_concurrency();
    min = 0;
    // 分割任务
    for (int i = 0; i < concurrent_count; ++i) {
        // 将函数封装为异步执行的任务
        std::packaged_task<double(int, int)> task(ConcurrentWorker);
        // 保存任务的结果
        results.push_back(task.get_future());
        int range = max / concurrent_count * (i + 1);
        std::thread t(std::move(task), min, range);
        t.detach();

        min = range + 1;
    }
    std::cout << "threads create finish" << std::endl;
    double sum = 0;
    for (auto& res : results) {
        sum += res.get();
    }
    // 返回结果
    // return sum;
    // 使用promise分离 任务结束 和 返回结果
    /**此处也可使用指针来接收结果，但是如果这个任务耗时较长，那么主线程只有在结果写入指针后才能继续（主线程被阻塞） */
    result->set_value(sum);
    std::cout << "concurrrent task finish." << std::endl;
}

int main() {
    auto start_time = std::chrono::steady_clock::now();
    std::promise<double> res;
    ConcurrentTask(0, MAX, &res);

    auto end_time = std::chrono::steady_clock::now();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    std::cout << "Concurrent task finish, " << ms << " ms consumed, Result: " << res.get_future().get() << std::endl;

    return 0;
}