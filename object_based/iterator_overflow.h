#ifndef ITERATOR_OVERFLOW_H
#define ITERATOR_OVERFLOW_H

#include <ostream>

class IteratorOverflow {
private:
    int index_;
    int max_;
public:
    IteratorOverflow(int index, int max)
        : index_(index), max_(max) {
    }
    int index() {
        return index_;
    }
    int max() {
        return max_;
    }
    void WhatHappend(std::ostream &os=std::cerr) {
        os << "Internal error: current index is " << index_
           << ", exceeds maximum bound: " << max_;
    }
};

#endif