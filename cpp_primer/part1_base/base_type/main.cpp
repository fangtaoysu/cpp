#include <iostream>
#include <typeinfo>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;


void TestTypeConvert() {
    unsigned int u = 10, u2 = 42;
    // 32
    std::cout << u2 - u << std::endl;
    // max uint -32
    std::cout << u - u2 << std::endl;

    int i = 10, i2 = 42;
    // 32
    std::cout << i2 - i << std::endl;
    // -32
    std::cout << i - i2 << std::endl;
    // 0
    std::cout << i - u << std::endl;
    // 0
    std::cout << u - i << std::endl;
}

void TestConst() {
    int val = 1;
    const int &ref_val = val;
    // 允许将变量引用赋值给常量引用，相当于传参时对函数操作参数的限制
    const int &const_ref_val = ref_val;
    val = 2;
    std::cout << "val: " << val
              << ", ref_val: " << ref_val
              << ", const ref val: " << const_ref_val << std::endl;

    
    const int i = 42;
    auto j = 1;
    const auto &k = i;
    auto *p = &i;
    const auto j2 = i;
    const auto &k2 = i;
    std::cout << "j: " << typeid(j).name() // int 
              << ", k: " << typeid(k).name() // const int& 
              << ", p: " << typeid(p).name() // const int*
              << ", j2: " << typeid(j2).name() // const int int 
              << ", k2: " << typeid(k2).name() << std::endl; // const int&
}

int main() {
    TestTypeConvert();
    TestConst();

    return 0;
}