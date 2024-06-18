#include <iostream>
#include <vector>
#include <typeinfo>
#include <array>
#include <list>
#include <forward_list>

using std::cout;
using std::endl;

void IteratorType() {
    std::vector<int> v1 = {1, 2, 3};
    const std::vector<int> v2 = {4, 5, 6};

    auto it1 = v1.begin();
    auto it2 = v2.begin();
    auto it3 = v1.cbegin();
    auto it4 = v2.cbegin();

    cout << "Type of it1: " << typeid(it1).name() << endl;
    cout << "Type of it2: " << typeid(it2).name() << endl;
    cout << "Type of it3: " << typeid(it3).name() << endl;
    cout << "Type of it4: " << typeid(it4).name() << endl;
}

void TestArray() {
    std::array<int, 5> arr = {1, 2, 3, 4, 5};
    std::array<int, 5> arr2 = {1};
    std::array<int, 5>::iterator it = arr.begin();
    while (it != arr.end()) {
        cout << *it++ << "\t";
    }
    arr = arr2; // array赋值的左右两边必须相等，其他容器的两边可以不相等，赋值后左值的大小等于右值的大小
    for (const auto val : arr) {
        cout << val << "\t";
    }
}

void TestInit() {
    std::list<int> ilst(10);
    std::list<double> dlst(ilst.begin(), ilst.end());
    for (const auto value : dlst) {
        cout << value << "\t";
    }
}

void TestAssign() {
    std::list<char*> ch_lst = {"abc", "def"};
    std::vector<std::string> str_vec;
    str_vec.assign(ch_lst.begin(), ch_lst.end());
    for (const auto &val : str_vec) {
        cout << val << "\t";
    }
}

void TestSize() {
    std::vector<int> ivec;
    cout << ivec.size() << "\t"
         << ivec.empty() << "\t"
         << ivec.max_size() << endl; // size_type类型
}

bool IsSame(std::list<int> &ilst, std::vector<int> &ivec) {
    if (ilst.empty() && ivec.empty()) {
        return true;
    }
    if (ilst.size() != ivec.size()) {
        return false;
    }
    auto it1 = ilst.begin();
    auto it2 = ilst.begin();
    while (it1 != ilst.end()) {
        // cout << *it1 << ", "
        //      << *it2 << endl;
        if (*it1 != *it2) { // 不能使用索引访问list中的元素
            return false;
        }
        it1++, it2++;
    }
    return true;
}

template <typename Begin, typename End>
void Print(Begin begin, End end) {
    while (begin != end) {
        cout << *begin++ << "\t";
    }
    cout << endl;
}

void TestInsert() {
    std::list<int> ilst(5, 1);
    Print(ilst.begin(), ilst.end());
    ilst.emplace_back(2);
    Print(ilst.begin(), ilst.end());
    // 等价于 ilst.push_front(0);
    ilst.insert(ilst.begin(), 0); // 0插入到第一个位置
    Print(ilst.begin(), ilst.end());

    // 读取IO流，逆序存储
    std::string word;
    std::list<std::string> lst;
    auto iter = lst.begin();
    while(std::cin >> word) {
        iter = lst.insert(iter, word);
    }
    Print(lst.begin(), lst.end());
}

void DeleteOdd(std::list<int> &lst) {
    auto it = lst.begin();
    while (it != lst.end()) {
        if (*it % 2) {
            it = lst.erase(it);
        } else {
            ++it;
        }
    }
}

void DelteForardList(std::forward_list<int> &lst) {
    auto prev = lst.before_begin();
    auto it = lst.begin();
    while (it != lst.end()) {
        if (*it % 2) { // 是奇数
            it = lst.erase_after(prev);
        } else {
            prev = it;
            ++it;
        }
    }
}

void TestVector() {
    std::vector<int> ivec;
    cout << "ivec: size: " << ivec.size()
         << ", ivec: capacity: " << ivec.capacity() << endl;
    // for (std::vector<int>::size_type ix = 0; ix < 10; ++ix) {
    //     ivec.push_back(ix);
    // }
    ivec.reserve(50); // 配置下次分配50的空间
    ivec.push_back(1);
    ivec.shrink_to_fit(); // 求求编译器将多余的内存退回给系统
    cout << "ivec: size: " << ivec.size()
         << ", ivec: capacity: " << ivec.capacity() << endl;
}

int main() {
    // IteratorType();
    // TestArray();
    // TestInit();
    // TestAssign();
    // TestSize();
    // std::list<int> ilst(5, 3);
    // std::vector<int> ivec(5, 3);
    // if (IsSame(ilst, ivec)) {
    //     cout << "they are same" << endl;
    // }
    // TestInsert();
    // std::forward_list<int> lst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // lst.resize(15); // 将5个值为0的元素添加到lst末尾
    // lst.resize(25, -1); // 将10个值为-1的元素添加到末尾
    // lst.resize(5); // 从lst末尾删20个元素
    // DelteForardList(lst);
    // Print(lst.begin(), lst.end());
    TestVector();
    return 0;
}
