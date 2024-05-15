#include <iostream>


int main() {
    const int a = 1;
    int& ref_a = const_cast<int&>(a);
    std::cout << "a address: " << &a
              << "\n reference a address: " << &ref_a << std::endl;

    ref_a = 12;

    std::cout << "chang a, a is : " << a
              << "\nreference a is : " << ref_a << std::endl;

    std::cout << "a address: " << &a
              << "\n reference a address: " << &ref_a << std::endl;

}