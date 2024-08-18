#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>
#include <map>
#include "./head_dir/print_string.h"

struct AbsInt {
    // 重载函数调用运算符（函数调用运算符必须重载在类中
    int operator() (int val) const {
        return val < 0 ? -val : val;
    }
};

class ShorterString {
public:
    bool operator() (const std::string& s1, const std::string& s2) const {
        return s1.size() < s2.size();
    }
};

class SizeComp {
public:
    SizeComp (size_t n) : sz_(n) {
    }
    bool operator() (const std::string &s) const {
        return s.size() >= sz_;
    }
private:
    size_t sz_;
};

void TestFunctionOperator() {
    std::vector<std::string> vs = {"abc", "efg", "hello", "effg", "g"};
    PrintString printer;
    // PrintString errors(std::cerr, '\n');
    // 函数对象常常作为泛型算法的实参
    std::for_each(vs.begin(), vs.end(), printer);
    // std::stable_sort(vs.begin(), vs.end(), ShorterString());
    std::stable_sort(vs.begin(), vs.end(), [] (const std::string& s1, const std::string& s2) {
        return s1.size() < s2.size();
    });
    std::for_each(vs.begin(), vs.end(), PrintString(std::cerr, '\n'));
    size_t sz = 2;
    // auto wc = std::find_if(vs.begin(), vs.end(), [sz] (const std::string& s) {
    //     return s.size() >= sz;
    // });
    auto wc = std::find_if(vs.begin(), vs.end(), SizeComp(sz));

}

void TestSTL() {
    std::plus<int> intAdd;
    std::negate<int> intNegate;
    int sum = intAdd(109, 11);
    sum = intNegate(sum + 10);
    std::cout << sum << std::endl;
    PrintString printer;
    std::vector<std::string> vs = {"abc", "efg", "hello", "effg", "g"};
    // 默认升序，此时按降序排列
    std::sort(vs.begin(), vs.end(), std::greater<std::string>());
    std::for_each(vs.begin(), vs.end(), printer);
}

int add (int a, int b) {
    return a + b;
}

struct divide {
public:
    int operator () (int a, int b) {
        return a / b;
    }
};

void FunctionTable() {
    // 用于存储指向可调用对象的指针
    std::map<std::string, int (*) (int, int)> binops; 
    binops.insert({"+", add});
    int res = binops["+"](4, 8);
    // 解决lambda表达式不匹配int (*) (int, int)类型的问题
    std::function<int(int, int)> f1 = add;
    std::function<int(int, int)> f2 = divide();
    std::function<int(int, int)> f3 = [] (int a, int b) {
        return a % b;
    };

    std::cout << res << std::endl;
    std::cout << f1(4, 2) << std::endl;
    std::cout << f2(4, 2) << std::endl;
    std::cout << f3(4, 2) << std::endl;
    std::map<std::string, std::function<int(int, int)>> bi = {
        {"+", add}
    };
}

class SmallInt {
public:
    SmallInt(int i = 0) : val_(i) {
        if (i < 0 || i > 255) {
            throw std::out_of_range("Bad SmallInt value");
        }
    }
    // 类型转换运算符，返回int类型
    // 没有返回类型，参数列表为空，通常为const
    // operator int() const { // 隐式执行
    //     return val_;
    // }
    // 显式执行(explicit 不隐式转化)
    explicit operator int() const {
        return val_;
    }
    explicit operator bool() const {
        return val_;
    }
private:
    std::size_t val_;
};

void TestConvert() {
    SmallInt si;
    si = 5; // 先将5隐式转化成SmallInt类型
    std::cout << static_cast<int>(si) << std::endl;
    // 先将si隐式转化为int，因此需要类型转化运算符的支持
    std::cout << static_cast<int>(si) + 5 << std::endl;
    SmallInt si1 = 3.14;
    std::cout << static_cast<int>(si1) << std::endl;
    // 类型转化运算符是隐式执行的，因此无法传参
    std::cout << static_cast<int>(si1) + 3.14 << std::endl;
    // 编译器显示转化位于条件部分的代码
    if (si) {
        std::cout << "convert success!" << std::endl;
    }
    
}

int main() {
    // int val = -2;
    // AbsInt abs;
    // int res = abs(val) + 2;
    // std::cout << res << std::endl;
    // TestFunctionOperator();
    // TestSTL();
    // FunctionTable();
    TestConvert();
    return 0;
}