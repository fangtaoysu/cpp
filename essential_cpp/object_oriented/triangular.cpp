#include "head_dir/triangular.h"
#include <math.h>


std::vector<int> Triangular::kElems_;

void Triangular::GenElems(int pos) const {
    if (kElems_.empty()) {
        kElems_.push_back(1);
        kElems_.push_back(2);
    }
    for (int n = kElems_.size(); n <= pos; ++n) {
        int n1 = kElems_[n - 1];
        int n2 = kElems_[n - 2];
        kElems_.push_back(n1 + n2);
    }
}

std::ostream& operator<<(std::ostream& os, const Triangular& triangular) {
    // std::cout << "Triangular\n";
    return triangular.Print(os);
}
