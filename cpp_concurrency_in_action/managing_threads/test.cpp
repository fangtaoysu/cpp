#include <iostream>
#include <thread>
#include <memory>
#include <chrono>

struct Func {
    explicit Func(int& data) : data(data) {}
    void operator()() {
        for (int i = 0; i < 5; ++i) {
            std::cout << "Thread accessing data: " << data << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    }
    int& data;
};

void TestJoin() {
    auto some_local_state = std::make_shared<int>(42);
    Func my_func(*some_local_state);
    std::thread t(my_func);

    try {
        // Simulate an exception in the main thread
        throw std::runtime_error("Simulated exception in main thread");
    } catch (...) {
        // Uncomment join to observe the difference
        t.join();
        std::cout << "Exception caught in main thread, but thread not joined!\n";
        throw;
    }

    t.join(); // Ensures proper thread cleanup
}

void TestDetach() {
    auto some_local_state = std::make_shared<int>(42);
    Func my_func(*some_local_state);
    std::thread t(my_func);

    // Detach the thread (thread becomes independent)
    t.detach();

    // Simulate variable destruction while thread is still running
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "some_local_state is going out of scope!\n";
}

int main() {
    std::cout << "=== Test with Join ===" << std::endl;
    try {
        TestJoin();
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test with Detach ===" << std::endl;
    TestDetach();

    // Allow time for detached thread to potentially cause undefined behavior
    std::this_thread::sleep_for(std::chrono::seconds(5));

    return 0;
}
