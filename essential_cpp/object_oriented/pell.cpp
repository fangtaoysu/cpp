#include "head_dir/pell.h"
#include <math.h>


std::vector<int> Pell::kElems_;

void Pell::GenElems(int pos) const {
    if (kElems_.empty()) {
        kElems_.push_back(1);
        kElems_.push_back(2);
    }
    for (int n = kElems_.size(); n <= pos; ++n) {
        int n1 = kElems_[n - 1];
        int n2 = kElems_[n - 2];
        kElems_.push_back(2 * n1 + n2);
    }
}

std::ostream& operator<<(std::ostream& os, const Pell& pell) {
    return pell.Print(os);
}
