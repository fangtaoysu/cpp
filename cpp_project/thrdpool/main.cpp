#include <condition_variable>
#include <functional>
#include <future>
#include <memeory>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>


namespace Diana {
    class ThreadPool {
    public:
        explicit ThreadPool(size_t threads = std::thread::hardware_concurrency()):stop(flase) {
            
        }
    }
}