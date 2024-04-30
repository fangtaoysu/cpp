#include "fibonacci.h"


std::vector<int> Fibonacci::kElems_;
int Fibonacci::Elem(int pos) const {
    if (!CheckIntegrity(pos)) {
        return 0;
    }
    if (pos > kElems_.size()) {
        Fibonacci::GenElems(pos);
    }
    return kElems_[pos-1];
}

void Fibonacci::GenElems(int pos) const {
    if (kElems_.empty()) {
        kElems_.push_back(1);
        kElems_.push_back(1);
    }
    if (kElems_.size() <= pos) {
        int ix = kElems_.size();
        int n1 = kElems_[ix-1];
        int n2 = kElems_[ix-1];
        for (; ix <= pos; ++ix) {
            int elem = n1 + n2;
            // std::cout << "GenElems: " << elem << std::endl;
            kElems_.push_back(elem);
            n2 = n1;
            n1 = elem;
        }
    }
}

std::ostream& Fibonacci::Print(std::ostream &os) const {
    int elem_pos_ = beg_pos_ - 1;
    int end_pos_ = elem_pos_ + length_;

    if (end_pos_ > kElems_.size()) {
        Fibonacci::GenElems(end_pos_);
    }
    while (elem_pos_ < end_pos_) {
        os << kElems_[elem_pos_++] << ' ';
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, const Fibonacci& fib) {
    // std::cout << "Fibonacci\n";
    return fib.Print(os);
}
