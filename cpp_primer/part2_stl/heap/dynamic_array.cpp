#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>


void Print(int* arr, std::size_t size) {
    for (int* p = arr; p != arr + size; ++p) {
        std::cout << *p << "\t";
    }
    std::cout << std::endl;
}

// unique_ptr传参只能传引用
void Print(std::unique_ptr<int[]> &arr, std::size_t size) {
    for (std::size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << "\t";
    }
    std::cout << std::endl;
}

void Print(std::shared_ptr<int[]> &arr, std::size_t size) {
    for (std::size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << "\t";
    }
    std::cout << std::endl;
}

void IsDelete(int* arr, const std::string &name) {
    if (!arr) {
        std::cout << name + "删除成功" << std::endl;
    } else {
        std::cout << name + "删除失败" << std::endl;
    }
}

void IsDelete(std::unique_ptr<int[]> &arr, const std::string &name) {
    if (!arr) {
        std::cout <<  name + "删除成功" << std::endl;
    } else {
        std::cout <<  name + "删除失败" << std::endl;
    }
}

void IsDelete(std::shared_ptr<int[]> &arr, const std::string &name) {
    if (!arr) {
        std::cout << name + "删除成功" << std::endl;
    } else {
        std::cout << name + "删除失败" << std::endl;
    }
}

void TestNew() {
    std::size_t size = 12;
    int *arr1 = new int[size];
    int *arr2 = new int [size]{1, 2, 3, 4, 54}; 
    Print(arr1, size);
    Print(arr2, size);

    delete [] arr1;
    delete [] arr2;

    // 使用new创建的数组，不能通过检查指针是否为空判断内存是否释放，同时需要手动设置指针为空
    arr1 = nullptr;
    arr2 = nullptr;
}

void TestUniquePtr() {
    std::size_t size = 12;
    std::unique_ptr<int[]> arr1(new int[size]);
    Print(arr1, size);
    arr1.reset();
    IsDelete(arr1, "arr1");
}

void TestSharedPtr() {
    std::size_t size = 12;
    // 使用shared_ptr声明数组时，需要提供删除器
    std::shared_ptr<int[]> sp(new int[size], [] (int* p) {
        delete [] p;
    });
    Print(sp, size);
    sp.reset();
    IsDelete(sp, "sp");
}

// const 修饰的是string而不是指针
// std::string* const 此时const修饰指针
void Print(const std::string* beg, const std::string* end) {
    while (beg != end) {
        std::cout << *beg++ << std::endl;
    }
}

void Print(int* beg, int* end) {
    while (beg != end) {
        std::cout << *beg++ << std::endl;
    }
}

void TestAllocator() {
    // 分离分配内存和调用构造函数操作
    std::size_t n = 12;
    std::allocator<std::string> alloc;
    // 分配内存
    // const std::string* 类型
    auto const p = alloc.allocate(n);
    auto q = p;
    // 调用构造函数构造字符串
    alloc.construct(q++);
    alloc.construct(q++, 10, 'c');
    Print(p, q);
    // 调用析构函数释放对象
    while (q != p) {
        alloc.destroy(--q);
    }
    // 释放内存
    alloc.deallocate(p, n);

    std::vector<int> vec{1, 3, 4, 5};
    std::allocator<int> alloc1;
    int* arr = alloc1.allocate(vec.size() * 2);
    // 复制
    int* q1 = std::uninitialized_copy(vec.begin(), vec.end(), arr);
    // 填充vec.size()个6
    std::uninitialized_fill_n(q1, vec.size(), 6);
    Print(arr, q1+vec.size());
}

int main() {
    // TestNew();
    // TestUniquePtr();
    // TestSharedPtr();
    TestAllocator(); 
    return 0;
}