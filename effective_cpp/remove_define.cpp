#include <iostream>
#include <vector>

void f(int a) { std::cout << a << std::endl; }
#define CALL_WIHT_MAX(a, b) (f((a) > (b) ? (a) : (b)))

template <typename T> inline void CallWithMax(const T &a, const T &b) {
    // 传入a,b的副本
    f(a > b ? a : b);
}

int main() {
    int a = 1;
    int b = 2;
    CALL_WIHT_MAX(++a, b + 3); // 5
    // 三元表达式比较过程中会调用一次自增，++a被选择，在传入函数f时再次自增
    CALL_WIHT_MAX(++a, b - 1); // 4
    // 解决方案：template内联函数
    int c = 2;
    int d = 2;
    CallWithMax(++c, d - 1);
}