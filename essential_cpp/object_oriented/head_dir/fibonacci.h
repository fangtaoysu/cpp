#ifndef FIBONACCI_H
#define FIBONACCI_H
#include "num_sequence.h"
#include <iostream>
#include <vector>
#include <ostream>

class Fibonacci : public NumSequence {
public:
    Fibonacci(int len=1, int beg_pos=1)
        : NumSequence(len, beg_pos, &kElems_) {
    }
    // Fibonacci(const Fibonacci&); // 使用对象赋值的构造函数

protected:
    virtual void GenElems(int pos) const;
    static std::vector<int> kElems_;
};


#endif