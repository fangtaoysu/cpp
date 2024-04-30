#include "num_sequence.h"

bool NumSequence::CheckIntegrity(int pos, int size) const {
    if (pos <= 0 || pos > max_elems_) {
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

ostream& operator<<(ostream &os, const NumSequence &ns) {
    return ns.Print(os);
}