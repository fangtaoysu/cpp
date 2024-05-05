#ifndef SQUARE_H
#define SQUARE_H
#include "num_sequence.h"
#include <iostream>
#include <vector>
#include <ostream>


class Square : public NumSequence {
public:
    Square(int len=1, int beg_pos=1)
        : NumSequence(len, beg_pos, &kElems_) {
    }
    virtual const char* WhatAmI() const {
        return "Square";
    }
    // friend std::ostream& operator<<(std::ostream& os, const Square& fib);

protected:
    virtual void GenElems(int pos) const;
    static std::vector<int> kElems_;
};


#endif