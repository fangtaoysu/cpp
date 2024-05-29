#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <initializer_list>
#include <cstdarg>
#include <cstdlib>
#include <cassert>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::begin;
using std::end;

void swap(int &val1, int &val2) {
    val1 ^= val2;
    val2 ^= val1;
    val1 ^= val2;
}

string::size_type FindChar(const string &s, char c, string::size_type &occurs) {
    auto res = s.size();
    occurs = 0;
    for (decltype(res) i = 0; i != s.size(); ++i) {
        if (s[i] == c) { 
            if (res == s.size()) { // 记录第一次
                res = i;
            }
            ++occurs;
        }
    }
    return res;
}

void Print(const int *beg, const int *end) {
    while (beg != end) {
        cout << *beg++ << ' ';
    }
}

// 使用引用为数组传参
void Print(int (&arr)[10]) {
    for(auto elem : arr) {
        cout << elem << endl;
    }
}

// 可变形参
void ErrorMsg(std::initializer_list<string> il) {
    for (auto beg = il.begin(); beg != il.end(); ++beg) {
        cout << *beg << " ";
    }
    cout << endl;
}

void PrintNumbers(int num, ...) {
    va_list args;
    va_start(args, num);

    for (int i = 0; i < num; ++i) {
        int value = va_arg(args, int);
        std::cout << value << " ";
    }

    va_end(args);
    std::cout << std::endl;
}

void TestParameter(int argc, char* argv[]) {
        int a = 1, b = 2;
    cout << "before swap:\na:" << a
         << ", b:" << b << endl;
    swap(a, b);
    cout << "swap:\na:" << a
         << ", b:" << b << endl;

    char ch = 'i';
    string s = "ddd, i am a person, i want to eat.";
    decltype(s.size()) occurs = 0;
    auto index = FindChar(s, ch, occurs);
    cout << "index:" << index
         << ", occurs: " << occurs << endl; 

    int arr[10] = {0};
    Print(arr);

    // 命令行传参
    cout << "argc: " << argc << "\n"; // 传参个数，默认是一个
    cout << "argv: " << argv[1] << endl; // 传参的内容，从./main 算起
    // 执行 ./main argc argv
    ErrorMsg({"hello"});
    ErrorMsg({"hello", "world"});
    ErrorMsg({"hello", "world", ",cpp"});

    PrintNumbers(3, 10, 20, 30);
    PrintNumbers(5, 1, 2, 3, 4, 5);

}

const string &Manip() {
    string res;
    if (!res.empty()) {
        return res; // 不要返回局部临时变量的引用
    } else {
        return "Empty"; // "Empty"也是局部临时对象
    }
}

vector<string> Process() {
    int val = 1;
    if (val == 1) {
        return {"func", "Process"};
    } else if (val == 2) {
        return {"hello"};
    } else {
        return {};
    }
}

// 返回数组指针
// typedef int arrT[10];
using arrT = int[10]; // 与上面等价含10个整数的数组
arrT* Func(int i);
auto Function(int i) -> int(*)[10];

const string &ShorterString(const string &s1, const string &s2) {
    #ifndef NDEBUG
    std::cerr << "function is running: " << __func__ << endl; // 存放函数名称
    cout << __FILE__ << " : " << __LINE__ << endl;
    return s1.size() <= s2.size() ? s1 : s2;
    #endif
}

// 使用const_cast改变const属性，实现重载
string &ShorterString(string &s1, string &s2) {
    auto &res = ShorterString(const_cast<const string&>(s1), const_cast<const string&>(s2));
    return const_cast<string&>(res);
}

void TestOverload() {
    string a = "short";
    string b = "longer";

    // Call overloaded function for non-const references
    string &result = ShorterString(a, b);
    cout << "Shorter string (non-const): " << result << endl;

    // Call original function for const references
    const string &constResult = ShorterString(static_cast<const string&>(a), static_cast<const string&>(b));
    cout << "Shorter string (const): " << constResult << endl;

}

void TestReturn() {
    // string res = Manip();
    // Process();
    TestOverload();
    assert(1 == 3);
}

int main(int argc, char *argv[]) {
    // TestParameter(argc, argv);
    TestReturn();
    return EXIT_SUCCESS; // cstdlib
    // return EXIT_FAILURE;
}