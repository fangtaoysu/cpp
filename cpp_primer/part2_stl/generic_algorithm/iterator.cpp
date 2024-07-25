#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <list>
#include <algorithm>
#include <fstream>


void Print(std::list<int>& lst) {
    for (auto val : lst) {
        std::cout << val << ' ';
    }
    std::cout << std::endl;
}

void TestInsertIterator() {
    // front_inserter 插入到第一个位置
    // inserter 插入到指定位置
    std::list<int> lst = {1, 2, 3, 4};
    std::list<int> lst1, lst2, lst3;
    // 逆序复制
    std::copy(lst.cbegin(), lst.cend(), std::front_inserter(lst1));
    // 正序复制
    std::copy(lst.cbegin(), lst.cend(), std::inserter(lst2, lst2.begin()));
    std::copy(lst.cbegin(), lst.cend(), std::back_inserter(lst3));
    Print(lst);
    Print(lst1);
    Print(lst2);
    Print(lst3);
}

void TestIOIterator() {
    std::istream_iterator<int> int_it(std::cin);
    std::istream_iterator<int> int_eof;
    std::ifstream in("afile"); 
    std::istream_iterator<std::string> str_it(in); // 构造函数赋值

    // std::vector<int> vec;
    // while (int_it != int_eof) {
    //     vec.push_back(*int_it++);
    // }

    std::vector<int> vec(int_it, int_eof);

    std::ostream_iterator<int> out_iter(std::cout, " ");

    for (const auto e : vec) {
        out_iter = e;
    }
    std::cout << std::endl;
}

void TestRearIterator() {
    std::ostream_iterator<int> out_iter(std::cout, " ");
    std::vector<int> vec = {0, 1, 2, 3, 4 ,5, 6, 7, 8, 9};
    // 正序
    std::sort(vec.begin(), vec.end());
    // 逆序
    std::sort(vec.rbegin(), vec.rend());
    // 反向迭代器
    for (auto r_iter = vec.crbegin(); r_iter != vec.crend(); ++r_iter) {
        *out_iter++ = *r_iter;
    }
    std::cout << std::endl;

    std::string str = "Lisa, have, a, apple.";
    auto comma = std::find(str.cbegin(), str.cend(), ',');
    // [str.cbegin(), comma)
    std::cout << std::string(str.cbegin(), comma) << std::endl; 
    auto rcomma = std::find(str.crbegin(), str.crend(), ',');
    // [rcomma.base(), str.cend())
    std::cout << std::string(rcomma.base(), str.cend()) << std::endl; 

}

int main() {
    // TestInsertIterator();
    // TestIOIterator();
    TestRearIterator();
    return 0;
}