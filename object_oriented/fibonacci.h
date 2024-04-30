#ifndef FIBONACCI_H
#define FIBONACCI_H
#include "num_sequence.h"
#include <iostream>
#include <vector>
#include <ostream>

class Fibonacci : public NumSequence {
public:
    Fibonacci(int len=1, int beg_pos=1)
        : length_(len), beg_pos_(beg_pos) {
    }
    virtual int Elem(int pos) const;
    virtual const char* WhatAmI() const {
        return "Fibonacci";
    }
    virtual std::ostream& Print(std::ostream &os=std::cout) const override;
    int Length() const {
        return length_;
    }
    int BegPos() const {
        return beg_pos_;
    }
    friend std::ostream& operator<<(std::ostream& os, const Fibonacci& fib);

protected:
    virtual void GenElems(int pos) const;
    bool CheckIntegrity(int pos) const;
    int length_;
    int beg_pos_;
    static std::vector<int> kElems_;
};

inline bool Fibonacci::CheckIntegrity(int pos) const {
    if (!NumSequence::CheckIntegrity(pos, kElems_.size())) {
        return false;
    }
    
    if (pos > kElems_.size()) {
        Fibonacci::GenElems(pos);
    }

    return true;
}

#endif