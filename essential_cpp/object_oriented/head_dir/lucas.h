#ifndef LUCAS_H
#define LUCAS_H
#include "num_sequence.h"
#include <iostream>
#include <vector>
#include <ostream>


class Lucas : public NumSequence {
public:
    Lucas(int len=1, int beg_pos=1)
        : NumSequence(len, beg_pos, &kElems_) {
    }
    // virtual const char* WhatAmI() const {
    //     return "Lucas";
    // }
    // friend std::ostream& operator<<(std::ostream& os, const Lucas& fib);

protected:
    virtual void GenElems(int pos) const;
    static std::vector<int> kElems_;
};


#endif