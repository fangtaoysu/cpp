#include <iostream>
#include <thread>

void Print(int val) { std::cout << val << std::endl; }

void GetID() {
    std::thread t{Print, 5};
    // t.detach();
    // 获取系统线程的id
    // 未分配任务或者detach时，没有id；thread::id of a non-executing thread
    if (t.get_id() == std::thread::id{}) {
        std::cout << "t not joinable." << std::endl;
    } else {
        std::cout << t.get_id() << std::endl;
    }
}

template <tpyename T> class SyncQueue<T> {};

class Consumer {
    SyncQueue<Message> &head_;
    Consumer(SynsQueue<Message> &q) : head_(q) {}
    void operator()(); // 从head获取消息
};

struct Producer {
    SynsQueue<Message> &tail_;
    Consumer(SyncQueue<Message> &q) : tail_(q) {}
    void operator()();
};

void MesssageQueue() {
    SyncQueue<Message> mq;
    Consumer c{mq};
    Producer p{mq};
    thread pro{p};
}

int main() {
    // GetID();
    MesssageQueue();

    return 0;
}