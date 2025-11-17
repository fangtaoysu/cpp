#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool data_ready = false;
int shared_data = 0;

void detailed_consumer(int id) {
    std::cout << "Consumer " << id << ": 创建unique_lock\n";
    std::unique_lock<std::mutex> lock(mtx);  // 步骤1: 锁定
    std::cout << "Consumer " << id << ": mutex已锁定，进入wait\n";
    
    // 步骤2: wait开始
    cv.wait(lock, [id]{
        std::cout << "Consumer " << id << ": 检查条件，data_ready=" 
                  << data_ready << "\n";
        return data_ready;
    });
    
    // 步骤4: wait结束，mutex重新锁定
    std::cout << "Consumer " << id << ": wait结束，mutex重新锁定\n";
    std::cout << "Consumer " << id << ": 消费数据: " << shared_data << "\n";
    
    // 步骤5: 离开作用域，自动解锁
    std::cout << "Consumer " << id << ": 离开作用域，自动解锁\n";
}

void producer() {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    
    {
        std::lock_guard<std::mutex> lock(mtx);  // 锁定mutex
        std::cout << "Producer: 生产数据...\n";
        shared_data = 42;
        data_ready = true;
    }  // 解锁mutex
    
    std::cout << "Producer: 发送通知...\n";
    cv.notify_all();  // 通知所有等待的消费者
}

int main() {
    std::cout << "=== 开始演示 condition_variable.wait 机制 ===\n";
    
    std::thread t1(detailed_consumer, 1);
    std::thread t2(detailed_consumer, 2);
    std::thread t3(producer);
    
    t1.join();
    t2.join();
    t3.join();
    
    return 0;
}