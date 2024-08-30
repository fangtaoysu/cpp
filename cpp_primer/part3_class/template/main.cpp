#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <memory>
#include <sstream>
#include <cstring>
#include "./head_dir/blob.h"
#include "./head_dir/blob_ptr.h"

// 显式实例化：避免多个文件中实例化相同的模版产生多余开销
// 实例化声明，必须是全局化声明
extern template class Blob<double>;
extern template class Blob<int>;


// template + 模版参数列表
// 默认模版实参
// 版本1
template <class T, typename F = std::less<T>>
int compare(const T& v1, const T& v2, F f = F()) {
    if (f(v1, v2)) { // 使用lesss确保类型无关
        return -1;
    } else if (f(v2, v1)) {
        return 1;
    }
    return 0;
}

// 版本2：兼容隐式转换
// template <class T, class A, typename F = std::less<T>>
// int compare(const T& v1, const A& v2, F f = F()) {
//     if (f(v1, v2)) { // 使用lesss确保类型无关
//         return -1;
//     } else if (f(v2, v1)) {
//         return 1;
//     }
//     return 0;
// }

// 非类型模版参数：实参必须是常量表达式
// 非类型参数：整数、指向对象或函数类型的指针（静态）、引用（静态）
// 不能处理字符指针的情况
// template <unsigned M, unsigned N>
// int compare1(const char (&p1)[M], const char (&p2)[N]) {
//     return strcmp(p1, p2);
// }

// 特例化的本质是实例化一个模版，而不是重载他，因此特例化不影响函数匹配
// 更一般的特例化模版 - 处理字符数组的指针
template <>
int compare<const char*>(const char* const &p1, const char* const &p2, std::less<> f) {
    std::cout << "run specialization version" << std::endl;
    return std::strcmp(p1, p2);
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

    const char *p3 = "hji", *p4 = "mom"; 
    std::cout << compare(p3, p4) << std::endl;
    
    // 模版只允许 模版类型发生const的转化 和 指针与数组的转化，其他类型的转化是非法的
    long lng = 10;
    // compare(lng, 1024); // 因此此处调用第二个版本
    // 或者去掉版本2，实例化模版
    compare<int>(10, 1024);
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

// 尾置返回:可以解析函数中的参数作为返回类型
// 所有迭代器操作都只会生成元素的引用
// 为了使用模版参数的成员，必须使用typename，因为type是一个类成员，需要使用typename告知编译器type是一个类型
template <typename It>
auto func(It beg, It end) -> typename std::remove_reference<decltype(*beg)>::type {
    return *beg;
}

void f(int v1, int &v2) {
    // 测试模版函数是否可以间接绑定到左值
    std::cout << v1 << " "
              << ++v2 << std::endl;
}

void g(int &&v1, int &v2) {
    // 测试模版函数是否可以间接绑定到右值
    std::cout << v1 << " " << ++v2 << std::endl;
}

template <typename F, typename T1, typename T2>
void Flip1(F f, T1 &&t1, T2 &&t2) {
    // 调用Filp1(f, b, 12)，b以int类型传递给f，12以int&类型传递给f
    // 调用Flip1(g, a, 12), a以int&类型传递给g，12以int&&类型传递给g
    f(std::forward<T2>(t2), std::forward<T1>(t1));
}

void TestReference() {
    // 成员模版
    DebugDelete bug;
    int* p = new int;
    // 第一个参数是未命名的int对象，第二个参数是删除器，当unique_ptr调用析构函数时，DebugDelete的调用运算符就会被实例化
    std::unique_ptr<int, DebugDelete> ptr(new int, DebugDelete());
    bug(p);
    std::cout << *p << std::endl;

    std::vector<int> vi = {1, 2, 4, 5, 6};
    // auto &i = func(vi.begin(), vi.end());
    auto i = func(vi.begin(), vi.end()); // 去除引用版本

    int a = 0, b = 0;
    f(12, a);
    // 通过Flip1 调用f并不会修改b的值，因为与v2绑定的是t1，而不是b
    Flip1(f, b, 12);
    std::cout << a << " "
              << b << std::endl;
    // g(a, 12);
    Flip1(g, a, 12);
}

template <typename T>
std::string DebugRep(const T &t) {
    std::ostringstream res;
    res << t;
    return res.str();
}

template <typename T>
std::string DebugRep(T *p) {
    std::ostringstream res;
    res << "pointer: " << p; // 打印指针本身的值
    if (p) {
        res << " " << DebugRep(*p);
    } else {
        res << " " << "null pointer";
    }
    return res.str();
}

// 解决字符数组的问题
std::string DebugRep(char *p) {
    return DebugRep(std::string(p));
}

std::string DebugRep(const char *p) {
    return DebugRep(std::string(p));
}

void TestOverload() {
    std::string s("hello");
    // 只有引用版本匹配
    std::cout << DebugRep(s) << std::endl;
    // 两个版本都匹配
    // 由于第二个版本是精确匹配，因此执行第二个版本
    std::cout << DebugRep(&s) << std::endl;
    // 在定义任何函数之前，记得声明所有重载的函数版本
}

template <typename T>
void Foo(const T &t) {
    std::cout << t;
}

template <typename T>
void PrintElement(const T& t) {
    std::cout << ", t: " << t;
}

template <typename T, typename... Args>
void Foo(const T &t, Args& ... rest) {
    std::cout << "rest类型参数数目：" << sizeof...(Args) << std::endl;
    std::cout << "rest函数参数数目：" << sizeof...(rest) << std::endl;
    Foo(t);
    // 递归拆包
    Foo(rest...); 
    // 折叠表达式拆包
    // ((std::cout << ", t: " << rest), ...);
    // lambda表达式拆包
    // auto print = [](const auto& arg) { std::cout << ", t: " << arg; };
    // (void)std::initializer_list<int>{(print(rest), 0)...}; 
    // tuple拆包
    // std::tuple<const Args&...> rest_tuple(rest...);
    // std::apply([](const auto&... args) { (PrintElement(args), ...); }, rest_tuple);

    std::cout << std::endl;
}

void VariadicTemplate() {
    int a = 0;
    double b = 10;
    long c = 200;
    std::string d = "abc";
    size_t e = 1;
    Foo(a, b, c, d);

}

int main() {
    FunctionTemplate();
    // ClassTemplate();
    // TestReference();
    // TestOverload();
    // VariadicTemplate();
    return 0;
}