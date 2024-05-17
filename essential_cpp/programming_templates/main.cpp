#include <iostream>
#include <string>
#include <sstream>

#include "head_dir/binary_tree.h"
#include "../tool/print_it.h"

void TestTree() {
    BinaryTree<std::string> bt;
    // bt.Insert(1);
    // bt.Insert(2);
    // bt.Insert(3);
    // bt.Insert(-1);
    // bt.Insert(7);
    // bt.Insert(9);
    // bt.Insert(6);
    bt.Insert("Piglet");
    bt.Insert("Eeyore");
    bt.Insert("Roo");
    bt.Insert("Tigger");
    bt.Insert("Chris");
    bt.Insert("Pooh");
    bt.Insert("Kanga");

    std::cout << "Preorder traversal: \n";
    bt.PreOrder();
    
    // bt.Remove(2);
    bt.Remove("Eeyore");
    std::cout << "\n\nPreorder traversal after Piglet removal: \n";
    bt.InOrder();

    // bt.Remove(3);
    bt.Remove("Piglet");
    std::cout << "\n\nPreorder traversal after Piglet Eeyore: \n";
    bt.PostOrder();

}

void TestPrint() {
    PrintIt<std::ostream> out(std::cout);
    out.Print("hello");
    out.Print(1024);
}

void TestConvert() {
    std::ostringstream msg;
    int a = 1;
    float b = 2.2;
    // 多类型转字符串
    msg << "hello, a=" << a
        << ", b=" << b
        << ", a+b=" << a+b;
    std::cout << msg.str();
}

template <int N>
struct Factorial {
    static const int value = N * Factorial<N - 1>::value;
};
template <>
struct Factorial<0> {
    static const int value = 1;
};
void TestExpression() {
    // 表达式作为模版参数：在编译时运算，用于固定数字的计算
    constexpr int result = Factorial<5>::value;
    std::cout << "Factorial of 5: " << result << std::endl;
}

int main() {
    TestTree();
    // TestPrint();
    // TestConvert();
    // TestExpression();
    return 0;
}
