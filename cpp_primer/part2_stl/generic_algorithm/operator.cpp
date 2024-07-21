#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void ElimDups(std::vector<std::string> &vec) {
    std::sort(vec.begin(), vec.end());
    // unqiue将相邻中重复的元素去掉，并返回最后一个不重复元素之后的位置
    auto end_unique = std::unique(vec.begin(), vec.end());
    // while (end_unique != vec.end()) {
    //     std::cout << *end_unique << "\t";
    // }
    vec.erase(end_unique, vec.end());
}

template <typename Iterator>
void Display(const Iterator beg, const Iterator end) {
    Iterator it = beg;
    while (it != end) {
        std::cout << *it++ << "\t";
    }
    std::cout << std::endl;
}

bool InShorter(const std::string &s1, const std::string &s2) {
    return s1.size() < s2.size();
}

void Biggies(std::vector<std::string> &words, vector<std::string>::size_type sz) {
    ElimDups(words);
    std::stable_sort(words.begin(), words.end(), InShorter);
    // 获取一个迭代器，指向第一个满足 size() >= sz 的元素
    // 计算满足 size >= sz 的元素数目
    // 打印长度大于等于给定值的单词
}

bool MoreThan5(const std::string &s) {
    return s.size() > 5;
}

int main() {
    std::vector<std::string> words = {
        "the", "red", "fox", "quick", "jumps", "turtle"
    };
    // ElimDups(words);
    // Display(words.begin(), words.end());
    // std::stable_sort(words.begin(), words.end(), InShorter);
    // Display(words.begin(), words.end());

    // std::partition(words.begin(), words.end, MoreThan5);
    // Display(words.begin(), words.end());


}