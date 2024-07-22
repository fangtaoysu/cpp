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

// stable_sort 和 find_if 都接受一个可调用对象，其返回值是bool类型
// 可调用对象：函数、函数指针、lambda表达式、重载运算符的类
void Biggies(std::vector<std::string> &words, std::vector<std::string>::size_type sz, std::ostream &os=std::cout, char c=' ') {
    // 先根据字母排序
    ElimDups(words);
    // 再根据长度排序（且不打乱原有排序）
    std::stable_sort(words.begin(), words.end(), [] (const std::string &s1, const std::string &s2) -> bool {
        return s1.size() < s2.size();
    });
    // 获取一个迭代器，指向第一个满足 size() >= sz 的元素
    // find_if 找到第一个满足条件的
    // auto first_it = std::find_if(words.begin(), words.end(), [sz] (const std::string &s) -> bool {
    //     return s.size() >= sz;
    // });
    // partition 谓词为true的在前半部分，谓词为false的在后半部分
    auto first_it = std::partition(words.begin(), words.end(), [sz] (const std::string &s) -> bool {
        return s.size() < sz;
    });
    // 打印长度大于等于给定值的单词
    std::for_each(first_it, words.end(), [&os, c] (const std::string &s) {os << s << c;});
    std::cout << std::endl;
}

bool MoreThan5(const std::string &s) {
    return s.size() > 5;
}

void TestLambda(std::vector<std::string> &words) {
    // lambda
    // lambda表达式不能直接使用函数体之外的变量，需要使用捕获列表[]传递外部变量
    auto f = [] (const std::vector<std::string> &words) -> std::string {        
        for (const auto & val : words) {
            std::cout << val << "\t";
        }
        std::cout << std::endl;
        return words[0];
    };
    std::cout << f(words) << std::endl;

    size_t v1 = 42;
    // 默认无法改变捕获的变量，使用关键字mutable
    auto f1 = [v1] () mutable { return ++v1; };
    v1 = 0;
    auto j = f1();
    std::cout << j << std::endl;
}

int main() {
    std::vector<std::string> words = {
        "the", "red", "fox", "quick", "a", "an", "jumps", "turtle"
    };
    // ElimDups(words);
    // Display(words.begin(), words.end());
    // std::stable_sort(words.begin(), words.end(), InShorter);
    // Display(words.begin(), words.end());

    // std::partition(words.begin(), words.end, MoreThan5);
    // Display(words.begin(), words.end());

    TestLambda(words);

    // Biggies(words, 4);
}