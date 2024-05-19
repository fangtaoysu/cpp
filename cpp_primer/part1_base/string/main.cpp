#include <iostream>
#include <typeinfo>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;


void Input() {
    string line;
    // 遇到文件结束符停止 ctrl d
    while (getline(cin, line)) {
        if (line.empty() || line.size() > 18) {
            continue;
        }
        cout << line << endl;
    }
}

auto CountPunct(string &str) -> decltype(str.size()) {
    /**
     * 统计字符串的标点符号个数， 返回值类型同str.size()类型
    */
    decltype(str.size()) count = 0;
    for (auto ch : str) {
        if (ispunct(ch)) {
            ++count;
        }
    }
    cout << "str is '" << str
        << "', the number of punct is " << count << endl;
    return count;
}

string ToUpper(string &str) {
    /**
     * 将字符串中每个单次的首字母改为大写
    */
    if (str.size() <= 0) {
        return str;
    }
    str[0] = toupper(str[0]);
    for (decltype(str.size()) index = 1; index != str.size(); ++index) {
        if (isspace(str[index]) && index + 1 < str.size()) {
            str[index+1] = toupper(str[index+1]);
        }
    }
    cout << "str is '" + str + "'" << endl;
    return str;
}

string ConvertHex(string::size_type n) {
    string result;
    const string hex_digits = "0123456789ABCDEF";
    if (n < hex_digits.size()) {
        result = hex_digits[n];
        cout << "n: " << n
             << ", convert hex is: " << hex_digits[n] << endl;
    }
    return result;
}


int main() {
    Input();
    string str2 = "hello world, are you ok?????!!!!";
    decltype(str2.size()) count = CountPunct(str2);
    string str = ToUpper(str2);
    string::size_type n;
    while (cin >> n) {
        ConvertHex(n);
    }
    return 0;
}