#include "head_dir/lucas.h"
#include <math.h>


std::vector<int> Lucas::kElems_;

void Lucas::GenElems(int pos) const {
    if (kElems_.empty()) {
        kElems_.push_back(2);
        kElems_.push_back(1);
    }
    for (int n = kElems_.size(); n <= pos; ++n) {
        int n1 = kElems_[n - 1];
        int n2 = kElems_[n - 2];
        kElems_.push_back(n1 + n2);
    }
}

std::ostream& operator<<(std::ostream& os, const Lucas& lucas) {
    return lucas.Print(os);
}
