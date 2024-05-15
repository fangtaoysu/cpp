#ifndef NUM_SEQUENCE_H
#define NUM_SEQUENCE_H

#include <vector>
#include <iostream>
#include <ostream>

template <int length, int beg_pos>
class NumSequence {
public:
    virtual ~NumSequence() {
    }

    int Elem(int pos) const;
    std::ostream& Print(std::ostream& os = std::cout) const;
    const char* WhatAmI() const;

    static int MaxElems() {
        return 64;
    }

protected:
    virtual void GenElems(int pos) const = 0;
    bool CheckIntegrity(int pos, int size) const;

    NumSequence(std::vector<int>* pe) : pelems_(pe) {
    }

    std::vector<int>* pelems_;
};

template <int length, int beg_pos>
std::ostream& operator<<(std::ostream& os, const NumSequence<length, beg_pos>& ns) {
    return ns.Print(os);
}

#endif