#ifndef PELL_H
#define PELL_H
#include "num_sequence.h"
#include <iostream>
#include <vector>
#include <ostream>


class Pell : public NumSequence {
public:
    Pell(int len=1, int beg_pos=1)
        : NumSequence(len, beg_pos, &kElems_) {
    }

protected:
    virtual void GenElems(int pos) const;
    static std::vector<int> kElems_;
};


#endif