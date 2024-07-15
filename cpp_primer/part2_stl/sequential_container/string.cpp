#include <string>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void Print(const std::string &s) {
    cout << s << endl;
}

void TestConstruct() {
    const char *cp = "abcdefgh"; // 以空字符结束的数组
    std::string s(cp); // 拷贝c风格的字符串为cpp风格，直至遇到空字符
    std::string s1(s, 2); // s是字符串，则取后面的[)
    std::string s2(cp, 2); // s是字符数组，则取前面的[)
    std::string s3(s, 1, 3);

    Print(s);
    Print(s1);
    Print(s2);
    Print(s3);
}

void ReplaceAll(std::string &s, const std::string &old_val, const std::string &new_val) {
    std::string::iterator it = s.begin();
    // while (it -  s.end() >= old_val.size()) {
    while (std::distance(it, s.end()) >= old_val.size()) {
        if (std::string(it, it+old_val.size()) == old_val) {
            it = s.erase(it, it+old_val.size());
            it = s.insert(it, new_val.begin(), new_val.end());;
            std::advance(it, new_val.size()); // it = it + new_val.size();
        } else {
            ++it;
        }
    }
}

// void ReplaceAll(std::string &s, const std::string &old_val, const std::string &new_val) {
//     for (size_t i = 0; i < s.size() - new_val.size(); ++i) {
//         if (std::string(s, i, old_val.size()) == old_val) {
//             s.replace(i, old_val.size(), new_val); // 从位置i开始，替换old_val长度的字符，为new_val
//         }
//     }
// }

std::string AddString(std::string &s, const std::string &pre, const std::string &end) {
    std::string result;
    result.assign(s);
    s.insert(0, pre);
    s.append(end);
    return s;
}

void FindAllNumber(const std::string &number, const std::string &name) {
    std::string::size_type pos = 0;
    // find_of系列查字符
    // 检索name中是否包含number中任意一个字符，如果包含，返回该位置的索引
    while ((pos = name.find_first_of(number, pos)) != std::string::npos) {
        cout << "found number at index: " << pos
             << " element is " << name[pos] << endl;
        ++pos;
    }
}

void FindNumberAndLetter(const std::string &s, const std::string &number) {
    std::string::size_type pos = 0;
    while ((pos = s.find_first_of(number, pos)) != std::string::npos) {
        cout << "number: " << s[pos]
             << "\tindex: " << pos << endl;
        ++pos;
    }
    pos = 0;
    while ((pos = s.find_first_not_of(number, pos)) != std::string::npos) {
        cout << "letter: " << s[pos]
             << "\tindex: " << pos << endl;
        ++pos;
    }
}

int main() {
    // TestConstruct();
    // std::string s = "abcbbbb";
    // ReplaceAll(s, "bb", "*");
    // Print(s);
    // std::string pre = "hello, ", end = "~";
    // std::string result = AddString(s, pre, end);
    // Print(result);
    // std::string number("0123456789"), name("abc123");
    // FindAllNumber(number, name);
    // std::string::size_type pos = name.find(number); // 查字符串
    // cout << pos << endl;

    std::string s = "ab23c5D43J53H6";
    std::string number = "0123456789";
    FindNumberAndLetter(s, number);
    return 0;
}