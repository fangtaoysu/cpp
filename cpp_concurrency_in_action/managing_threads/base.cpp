#include <iostream>
#include <thread>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <mutex>
#include <cmath>
#include <vector>
#include <mutex>


void Hello() {
    std::cout << "hello world from new thread." << std::endl;
}

void HelloWithParams(std::string str) {
    std::cout << "hello, " << str << std::endl;
}

void PrintTime() {
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);
    
    std::stringstream ss;
    ss << std::put_time(localtime(&in_time_t), "%Y-%m-%d %X");
    std::cout << "now is: " << ss.str() << std::endl;
}

void SleepThread() {
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "[thread-" << std::this_thread::get_id() << "] is waking up" << std::endl;
}

void LoopThread() {
    for (int i = 0; i < 10; ++i) {
        std::cout << "[thread-" << std::this_thread::get_id() << "] print: " << i << std::endl; 
    }
}

void Init() {
    std::cout << "Initialing..." << std::endl;
}

void Worker1(std::once_flag* flag) {
    // 初始化任务
    std::call_once(*flag, Init); // 传入调用一次的标志和需要调用的函数
    // 其他任务...
}

static const int MAX = 10e8;
static double sum = 0;
static std::mutex m;
void Worker2(int min, int max) {
    double tmp = 0;
    for (int i = min; i <= max; ++i) {
        // m.lock();
        tmp += sqrt(i);
        // m.unlock();
    }
    m.lock();
    sum += tmp;
    m.unlock();
}

void SerialTask(int min, int max) {
    auto start_time = std::chrono::steady_clock::now();
    sum = 0;
    Worker2(0, MAX);
    auto end_time = std::chrono::steady_clock::now();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    std::cout << "Serial task finish, " << ms << " ms consumed, Result: " << sum << std::endl;
}

void ConcurrentTask(int min, int max) {
    auto start_time = std::chrono::steady_clock::now();
    
    unsigned concurrent_cout = std::thread::hardware_concurrency();
    std::cout << "hardware_concurrency: " << concurrent_cout << std::endl;
    std::vector<std::thread> threads;
    min = 0;
    sum = 0;
    for (int t = 0; t < concurrent_cout; ++t) {
        int range = max / concurrent_cout * (t + 1);
        threads.push_back(std::thread(Worker2, min, range));
        min = range + 1;
    }
    for (auto& t : threads) {
        t.join();
    }

    auto end_time = std::chrono::steady_clock::now();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    std::cout << "Concurrent task finish, " << ms << " ms consumed, Result: " << sum << std::endl;
}

int main() {
    std::cout << "[main thread-" << std::this_thread::get_id() << "]" << std::endl;
    // 启动一个线程
    std::thread t1(Hello);
    t1.join();
    // 带参的线程任务
    std::thread t2(HelloWithParams, "wsl");
    t2.join();

    // join与detach
    PrintTime();
    std::thread t3(SleepThread);
    std::thread t4(LoopThread);
    // join 和 detach 配置新线程与当前线程的关系
    t3.join(); // 当前线程（被阻塞）等到新线程运行完成
    t4.detach(); // 当前线程与新线程分离
    PrintTime();

    // 仅调用一次
    std::once_flag flag;
    std::thread t5(Worker1, &flag);
    std::thread t6(Worker1, &flag);
    std::thread t7(Worker1, &flag);
    t5.join();
    t6.join();
    t7.join();

    SerialTask(0, MAX);
    ConcurrentTask(0, MAX);
    return 0;

    // https://zhuanlan.zhihu.com/p/340278634
}
