#include <vector>
#include <iostream>
#include <string>
using std::string;
using std::vector;
using std::cout;
using std::endl;

string SplicingString(vector<string> str_vec) {
    string result;
    for (auto it = str_vec.cbegin() ; it != str_vec.cend(); ++it) {
        for (auto ch : (*it)) {
            if (!isspace(ch)) {
                result += ch;
            }
        }
    }
    return result;
}

bool BinarySearch(vector<int> vec, int val) {
    auto beg = vec.begin();
    auto end = vec.end();
    auto mid = beg + (end - beg) / 2;
    while (mid != end) {
        if (*mid > val) {
            end = mid;
        } else if(*mid < val) {
            beg = mid + 1;
        } else {
            return true;
        }
        mid = beg + (end - beg) / 2;
    }
    return false;
}
int main() {
    // vector<string> str_vec{"1234 567\n89", "abc def g\thj"};
    // string str = SplicingString(str_vec);
    // cout << str << endl;
    vector<int > vec{1, 2, 3, 5, 9, 100};
    bool result = BinarySearch(vec, 5);
    if (result) {
        cout << "found it!" << endl;
    }
    return 0;
}