#include "head_dir/binary_tree.h"
#include <iostream>
#include <string>
// 模版在头文件外实现

void Test() {
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

    std::cout << "Preorder traversal: \n";
    bt.PreOrder();
    
    // bt.Remove("Piglet");
    bt.Remove(2);

    std::cout << "\n\nPreorder traversal after Piglet removal: \n";
    bt.InOrder();

    // bt.Remove("Eeyore");
    bt.Remove(3);

    std::cout << "\n\nPreorder traversal after Piglet Eeyore: \n";
    bt.PostOrder();

}

int main() {
    Test();

    return 0;
}
