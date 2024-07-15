#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <stack>


int main() {
    std::vector<int> ivec(10, 1);
    // 基于vector构造stack并将ivec的内容拷贝给stack
    // 适配器：使某种事物行为看起来像另一种事物
    // 适配器：添加、删除元素；访问尾元素
    std::stack<int, std::vector<int>> stk(ivec);
    while (!stk.empty()) {
        int val = stk.top();
        std::cout << val << "\t";
        stk.pop();
    }
    return 0;
}