#include <iostream>
#include <vector>
#include <string>
#include <memory>


void UniquePtr() {
    std::unique_ptr<int> pointer(new int(5));
    // 只允许一个指针指向给定对象
    // 因此不支持拷贝和赋值
    // std::unique_ptr<int> p(pointer);
    // std::unique_ptr<int> p1 = p;
    std::cout << *pointer << std::endl;
    // 转移指针的所有权
    // release() 释放控制权，切断指针与对象地址的联系
    // delete 释放指针所指对象地址的内存
    std::unique_ptr<int> p1(pointer.release());
    std::unique_ptr<int> p2(new int(10));
    std::cout << *p1 << "\t" 
              << *p2 << std::endl;
    // reset() 重置所指对象，默认置空
    p1.reset(p2.release()); // p2释放对指针的控制权，并返回指针，p1指向该对象
    std::cout << *p1 << std::endl;
}

void WeakPtr() {
    auto p = std::make_shared<int>(12);
    std::weak_ptr<int> wp(p); // p的引用次数未改变
    // 如果wp.use_count() 为0，wp.lock()返回空 shared_ptr
    if (std::shared_ptr<int> np = wp.lock()) { // np不为空则条件成立
        std::cout << *np << "\t"
                  << np.use_count() << std::endl;
    }
}

int main() {
    // UniquePtr();
    WeakPtr();
    return 0;
}