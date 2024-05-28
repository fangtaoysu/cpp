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

void TestSwitch() {
    unsigned a_cnt = 0, e_cnt = 0, i_cnt = 0, o_cnt = 0, u_cnt = 0;
    char ch;
    while (cin >> ch) {
        switch (ch) {
            case 'a':
                ++a_cnt;
                break;
            case 'e':
                ++e_cnt;
                break;
            case 'i':
                ++i_cnt;
                break;
            case 'o':
                ++o_cnt;
                break;
            case 'u':
                ++u_cnt;
                break;
        }
    }
}

void PrintSmaller() {
    int val1, val2;
    bool tag = true;
    do {
        cout << "input two val:" << endl;
        cin >> val1 >> val2;
        cout << ((val1 < val2) ? val1 : val2) << endl;
        char ch;
        cout << "continue or not?(y/n)" << endl;
        cin >> ch;
        tag = (ch == 'y' || ch == 'Y');
    } while (tag);
}

int divide(int numerator, int denominator) {
    if (denominator == 0) {
        // Throwing an exception if the denominator is zero
        throw std::invalid_argument("Division by zero is not allowed.");
    }
    return numerator / denominator;
}

void TestTry() {
    int num = 10;
    int denom = 0;

    try {
        // Trying to divide by zero
        int result = divide(num, denom);
        std::cout << "Result: " << result << std::endl;
        std::cout << "Program continues..." << std::endl;
    } catch (const std::invalid_argument& e) {
        // Catching the exception and handling it
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << "Program continues..." << std::endl;
}

int main() {
    // TestSwitch();
    // PrintSmaller();
    TestTry();
    return 0;
}