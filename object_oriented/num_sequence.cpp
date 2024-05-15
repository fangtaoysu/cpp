#include "head_dir/num_sequence.h"
#include <typeinfo>

template <int length, int beg_pos>
bool NumSequence<length, beg_pos>::CheckIntegrity(int pos, int size) const {
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

template <int length, int beg_pos>
std::ostream& operator<<(std::ostream& os, const NumSequence<length, beg_pos>& ns) {
    return ns.Print(os);
}

template <int length, int beg_pos>
int NumSequence<length, beg_pos>::Elem(int pos) const {
    if (!CheckIntegrity(pos, (*pelems_).size())) {
        return 0;
    }
    return (*pelems_)[pos-1];
}

template <int length, int beg_pos>
const char* NumSequence<length, beg_pos>::WhatAmI() const {
    // 9Fibonacci 9是Fibonacci字符串长度
    return typeid(*this).name();
}

template <int length, int beg_pos>
std::ostream& NumSequence<length, beg_pos>::Print(std::ostream &os) const {
    int elem_pos_ = beg_pos - 1;
    int end_pos_ = elem_pos_ + length;

    if (end_pos_ > (*pelems_).size()) {
        GenElems(end_pos_);
    }
    os << WhatAmI() << ":("
       << beg_pos << " "
       << length << ") ==> ";
    while (elem_pos_ < end_pos_) {
        os << (*pelems_)[elem_pos_++] << ' ';
    }
    return os;
}
