#include "head_dir/pentagonal.h"
#include <math.h>


std::vector<int> Pentagonal::kElems_;

void Pentagonal::GenElems(int pos) const {
    for (int n = kElems_.size(); n <= pos; ++n) {
        kElems_.push_back(int((3 * pow(n, 2) - n) / 2));
    }
}

std::ostream& operator<<(std::ostream& os, const Pentagonal& pentagonal) {
    return pentagonal.Print(os);
}
