#ifndef STACK_H
#define STACK_H

#include <vector>
#include <string>
#include <iostream>
#include <istream>

using namespace std;
class Stack {
public:
    bool Push(const string&);
    bool Pop(string &elem);
    bool Peek(string &elem); // 读栈顶
    bool Empty() {return stack_.empty();};
    bool Full() {return stack_.size() == max_size_;};

    int size() {return stack_.size();}

private:
    vector<string> stack_;
    static int max_size_;

    // 类内部声明并定义
    void CreateStack(Stack &stack, istream &is=std::cin) {
        string str;
        while (cin >> str && !stack.Full()) {
            stack.Push(str);
        }
        cout << "Read in " << stack.size() << " elements\n";
    }
};

#endif