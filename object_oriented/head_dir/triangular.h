#ifndef TRIANGULAR_H
#define TRIANGULAR_H
#include "num_sequence.h"
#include <iostream>
#include <vector>
#include <ostream>

class Triangular : public NumSequence {
public:
    Triangular(int len=1, int beg_pos=1)
        : NumSequence(len, beg_pos, &kElems_) {
    }
    // virtual int Elem(int pos) const;
    virtual const char* WhatAmI() const {
        return "Triangular";
    }
    // friend std::ostream& operator<<(std::ostream& os, const Triangular& fib);

protected:
    virtual void GenElems(int pos) const;
    static std::vector<int> kElems_;
};

#endif