#include "stack.h"

int Stack::max_size_ = 5;
// 类内部声明外部定义
bool Stack::Pop(string &elem) {
    if (Empty()) {
        return false;
    }
    elem = stack_.back();
    stack_.pop_back();
    return true;
}

bool Stack::Peek(string &elem) {
    if (Empty()) {
        return false;
    }
    elem = stack_.back();
    return true;
}

bool Stack::Push(const string &elem) {
    if (Full()) {
        return false;
    }
    stack_.push_back(elem);
    return true;
}