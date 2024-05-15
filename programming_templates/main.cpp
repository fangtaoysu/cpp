#include "head_dir/binary_tree.h"
#include "../tool/print_it.h"
#include <iostream>
#include <string>
#include <sstream>
#include "head_dir/fibonacci.h"
#include "head_dir/num_sequence.h"

void TestTree() {
    // issue1
    BinaryTree<int> bt;
    bt.Insert(1);
    bt.Insert(2);
    bt.Insert(3);
    bt.Insert(-1);
    bt.Insert(7);
    bt.Insert(9);
    bt.Insert(6);
    // bt.Insert("Piglet");
    // bt.Insert("Eeyore");
    // bt.Insert("Roo");
    // bt.Insert("Tigger");
    // bt.Insert("Chris");
    // bt.Insert("Pooh");
    // bt.Insert("Kanga");

    // std::cout << "Preorder traversal: \n";
    // bt.PreOrder();
    
    // bt.Remove("Piglet");
    // bt.Remove(2);

    // std::cout << "\n\nPreorder traversal after Piglet removal: \n";
    // bt.InOrder();

    // bt.Remove("Eeyore");
    // bt.Remove(3);

    // std::cout << "\n\nPreorder traversal after Piglet Eeyore: \n";
    // bt.PostOrder();

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

void TestInherit() {
    // issue2
    // 主要用于测试表达式作为参数的类模版
    Fibonacci<4> fib1;
    std::cout << fib1 << std::endl;
    Fibonacci<8, 9> fib2;
    std::cout << fib2 << std::endl;
    Fibonacci<12, 13> fib3;
    std::cout << fib3 << std::endl;
}

int main() {
    TestTree();
    // TestPrint();
    // TestConvert();
    TestInherit();
    return 0;
}
