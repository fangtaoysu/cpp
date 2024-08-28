#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <memory>
#include "./head_dir/blob.h"
#include "./head_dir/blob_ptr.h"

// 显式实例化：避免多个文件中实例化相同的模版产生多余开销
// 实例化声明，必须是全局化声明
extern template class Blob<double>;
extern template class Blob<int>;


// template + 模版参数列表
// 默认模版实参
template <class T, typename F = std::less<T>>
int compare(const T& v1, const T& v2, F f = F()) {
    if (f(v1, v2)) { // 使用lesss确保类型无关
        return -1;
    } else if (f(v2, v1)) {
        return 1;
    }
    return 0;
}

// 非类型模版参数：实参必须是常量表达式
// 非类型参数：整数、指向对象或函数类型的指针（静态）、引用（静态）
template <unsigned M, unsigned N>
int compare1(const char (&p1)[M], const char (&p2)[N]) {
    return strcmp(p1, p2);
}

void FunctionTemplate() {
    std::cout << compare(1, 0) << std::endl;
    std::vector<int> vec1{1, 5, 3}, vec2{3, 4, 5};
    std::cout << compare(vec1, vec2) << std::endl;

    int arr1[] = {1, 2, 3};
    int arr2[] = {0, 2, 3};
    // 数组指针
    int (*p1)[] = &arr1;
    int (*p2)[] = &arr2;
    std::cout << compare(p1, p2) << std::endl;

    std::cout << compare1("hi", "hello") << std::endl;
}

// 可以为类模板定义一个类型别名
template <typename T> using twin = std::pair<T, T>;
void ClassTemplate() {
    twin<int> win_loss = {1, 2};
    std::cout << win_loss.first << win_loss.second << std::endl;

    Blob<double> ia = {.3, .423, 32.4, 2423.23}; // Default constructor
    Blob<int> ia1 = {0, 2, 3, 34}; // Initializer list constructor
    
    ia.Print(); // Prints: 0 2 3 34
    ia1.Print(); // Prints: 0 2 3 34

    ia1.push_back(99); // Adds 99 to the end of the Blob
    ia1.Print(); // Prints: 0 2 3 34 99

    ia1.pop_back(); // Removes the last element 
    BlobPtr ptr(ia1);
    std::vector<long> vi = {0, 12, 3, 55};
    Blob<int> al(vi.begin(), vi.end());
    al.Print();
}

class DebugDelete {
public:
    DebugDelete(std::ostream &s = std::cerr) : os_(s) {
    }
    template <typename T> void operator() (T *p) const {
        os_ << "deleting unique_ptr" << std::endl;
    }
private:
    std::ostream &os_;    
};

void Test() {
    // 成员模版
    DebugDelete bug;
    int* p = new int;
    // 第一个参数是未命名的int对象，第二个参数是删除器，当unique_ptr调用析构函数时，DebugDelete的调用运算符就会被实例化
    std::unique_ptr<int, DebugDelete> ptr(new int, DebugDelete());
    bug(p);
    std::cout << *p << std::endl;
}

int main() {
    // FunctionTemplate();
    ClassTemplate();
    // Test();
    return 0;
}