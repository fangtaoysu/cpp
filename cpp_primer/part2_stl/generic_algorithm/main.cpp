#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>


void ReadAlgorithm() {
    std::vector<int> ivec;
    std::vector<std::string> svec;
    for (int i = 0; i < 10; i++) {
        ivec.push_back(i+1);
        svec.push_back(std::to_string(i+1));
    }
    // 对容器中所有元素和第三个参数做+运算
    int isum = accumulate(ivec.cbegin(), ivec.cend(), 0);
    std::string ssum = accumulate(svec.cbegin(), svec.cend(), std::string(""));
    std::cout << "int vector sum is: " << isum 
              << "\nstring vector sum is: " << ssum << std::endl; 
}

void Display(const std::vector<int>::iterator beg, const std::vector<int>::iterator end) {
    std::vector<int>::iterator it = beg;
    while (it != end) {
        std::cout << *it++ << "\t";
    }
    std::cout << std::endl;
}

void WriteAlgorithm() {
    std::vector<int> ivec(10, 4);
    Display(ivec.begin(), ivec.end());
    std::fill(ivec.begin(), ivec.begin() + ivec.size() / 2, 0);
    Display(ivec.begin(), ivec.end());
    std::fill_n(ivec.begin(), ivec.size(), 1);
    Display(ivec.begin(), ivec.end());
    std::vector<int> vec;
    // 通过begin或end方法获取的迭代器只能用于修改这个位置的值，如果想要插入，会 segementation fault
    // 因此可以通过 back_inserter 迭代器向容器插入元素
    auto it = std::back_inserter(vec);
    *it = 10;
    Display(vec.begin(), vec.end());
    std::fill_n(ivec.end(), 10, -1); // end()返回的迭代器无法修改容器，因此这一步没有变化
    Display(ivec.begin(), ivec.end());
    std::fill_n(std::back_inserter(vec), 10, -1); // back_inserter是插入迭代器，每次会向容器插入10个元素
    Display(vec.begin(), vec.end());
    // back_inserter大多用于给标准库算法的空容器传参，如copy，如果传入空容器的vec.begin()会得到空指针错误
    std::vector<int> vec1;
    std::copy(vec.begin(), vec.end(), std::back_inserter(vec1));
    Display(vec1.begin(), vec1.end());
    std::replace(vec.begin(), vec.end(), -1, 0);
    Display(vec.begin(), vec.end());
    // 替换vec中的元素 10 -> 0, 并将结果保存在vec1中
    std::replace_copy(vec.begin(), vec.end(), vec1.begin(), 10, 0);
    Display(vec.begin(), vec.end());
    Display(vec1.begin(), vec1.end());
}

void elim_dups(std::vector<int> &vec) {
    std::sort(vec.begin(), vec.end());
    // unqiue将相邻中重复的元素去掉，并返回最后一个不重复元素之后的位置
    auto end_unique = std::unique(vec.begin(), vec.end());
    // while (end_unique != vec.end()) {
    //     std::cout << *end_unique << "\t";
    // }
    vec.erase(end_unique, vec.end());
}

void SortAlgorithm() {
    /**
     * 等价于 elim_dups(vec);
     */
    std::vector<int> vec = {1, 2, 3, 3, 4, 5, 5, 6, 7, 7, 9};
    auto first = vec.begin();
    auto result = first;
    while(++first != vec.end()) {
        // first 和 result 是两个指针
        /**
         * 如果相邻两个值不相等，first 和 result 均自增
         * 如果相等，只有first自增
         * 如果两个指针指向元素不相等 && 两个指针不相邻，更新result指针指向的值
         */
        if (!(*result == *first) && (++result != first)) {
            std::cout << "first: " << *first
                      << "\tresult: " << *result << std::endl;
            *result = std::move(*first);
        }
    }
    // Display(vec.begin(), vec.end());
    // vec.erase(++result, vec.end());
    // Display(vec.begin(), vec.end());
}

int main() {
    // ReadAlgorithm();
    // WriteAlgorithm();
    SortAlgorithm();

    return 0;
}