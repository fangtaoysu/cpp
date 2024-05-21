#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <chrono>
#include <ctime>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::begin;
using std::end;

void Test() {
    constexpr size_t SIZE = 5;
    int arr[SIZE] = {0};
    constexpr size_t size = sizeof(arr) / sizeof(int);
    vector<int> vec(begin(arr), end(arr));
    cout << *vec.begin() << endl;
    cout << *vec.begin() + 1 << endl;

    int val = 0;
    cout << val << ' ' << ++val << endl;
    val = 1 == 2;
    cout << val << endl;

}

void TestConvert() {
    // 强制类型转换
    int val = 0;
    void *p = &val;
    double *d_ptr = static_cast<double*>(p);
    // 去掉const性质
    const int pc = 12;
    int *ptr = const_cast<int*>(&pc);
    *ptr = 10;
    cout << *ptr << endl;
}

int main() {
    // Test();
    TestConvert();
    return 0;
}