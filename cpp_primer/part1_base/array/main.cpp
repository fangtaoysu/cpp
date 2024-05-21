#include <iostream>
#include <iterator>
#include "string.h"
#include <string>
#include <iterator>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::begin;
using std::end;


void TestArray() {
    constexpr size_t SIZE = 10;
    int arr[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int *end = &(arr[SIZE]);
    // for (int *beg = arr; beg != end; ++beg) {
    //     cout << *beg << endl;
    // }
    int *beg = std::begin(arr);
    int *last = std::end(arr);
    // while (beg != last) {
    //     cout << *beg++ << " ";
    // }
    cout << (arr + SIZE)[-1] << " "
         << (arr + SIZE)[-2] << endl;
}

void TestChar() {
    char ca[] = {'c', '+', '\0', '+'};
    cout << strlen(ca) << endl;
}

void TestConvert() {
    char c_string[] = {'c', 'p', '\0'};
    string str = c_string;
    cout << str << endl;
    const char *c_str = str.c_str();
    str += "p";
    for (auto i = 0; i < strlen(c_str); ++i) {
        cout << c_str[i];
    }
}

int TestMultiDimenArr() {
    constexpr size_t row = 3, col = 4;
    int ix[row][col] = {0, 3, 6, 9};
    // 使用for
    for (size_t i = 0; i != row; ++i) {
        for (size_t j = 0; j != col; ++j) {
            cout << ix[i][j] << ' ';
        }
        cout << endl;
    }
    // 使用范围for
    for (const auto &row : ix) {
        for (auto &col : row) {
            cout << col << " ";
        }
        cout << "\n";
    }
    // 使用迭代器
    for (auto p = begin(ix); p != end(ix); ++p) {
        for (auto q = begin(*p); q != end(*p); ++q) {
            cout << *q << " ";
        }
        cout << "\n";
    }
    // 使用别名
    using int_array = int[col];
    for (int_array *p = ix; p != ix + row; ++p) {
        for (int *q = *p; q != *p + col; ++q) {
            cout << *q << " ";
        }
        cout << endl;
    }
}

int main() {
    // TestArray();
    // TestChar();
    // TestConvert();
    TestMultiDimenArr();
    return 0;
}