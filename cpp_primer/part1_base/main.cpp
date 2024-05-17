#include <iostream>

void TestTypeConvert() {
    unsigned int u = 10, u2 = 42;
    // 32
    std::cout << u2 - u << std::endl;
    // max uint -32
    std::cout << u - u2 << std::endl;

    int i = 10, i2 = 42;
    // 32
    std::cout << i2 - i << std::endl;
    // -32
    std::cout << i - i2 << std::endl;
    // 0
    std::cout << i - u << std::endl;
    // 0
    std::cout << u - i << std::endl;
}

void Test() {
    std::string str;
    char ch;
    std::cout << "str: " << str
              << ", ch: " << ch << std::endl;

}

int main() {
    // TestTypeConvert();
    Test();

    return 0;
}