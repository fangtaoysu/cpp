#include "head_dir/num_sequence.h"
#include <typeinfo>


bool NumSequence::CheckIntegrity(int pos, int size) const {
    if (pos <= 0 || pos > MaxElems()) {
        std::cout << "Oop! invalid position: " << pos
             << " Cannot honor request\n";
        return false;
    }
    if (pos > size) {
        // 通过虚拟机制调用对应序列的GenElems
        GenElems(pos);
    }
    return true;
}

std::ostream& operator<<(std::ostream &os, const NumSequence &ns) {
    // std::cout << "NumSequence\n";
    return ns.Print(os);
}

int NumSequence::Elem(int pos) const {
    if (!CheckIntegrity(pos, (*pelems_).size())) {
        return 0;
    }
    return (*pelems_)[pos-1];
}

const char* NumSequence::WhatAmI() const {
    // 9Fibonacci 9是Fibonacci字符串长度
    return typeid(*this).name();
}

std::ostream& NumSequence::Print(std::ostream &os) const {
    int elem_pos_ = beg_pos_ - 1;
    int end_pos_ = elem_pos_ + length_;

    if (end_pos_ > (*pelems_).size()) {
        GenElems(end_pos_);
    }
    os << WhatAmI() << ":("
       << beg_pos_ << " "
       << length_ << ") ==> ";
    while (elem_pos_ < end_pos_) {
        os << (*pelems_)[elem_pos_++] << ' ';
    }
    return os;
}
