#include "num_sequence.h"

typedef NumSequence::PtrType PtrType;
PtrType NumSequence::kFuncTbl_[kNumSeq_] = {
    0,
    &NumSequence::Fibonacci,
    &NumSequence::Pell,
    &NumSequence::Lucas,
    &NumSequence::Trinagular,
    &NumSequence::Sequare,
    &NumSequence::Pentagonal
};

int NumSequence::Elem(int pos) {
    if (!CheckIntegrity(pos)) {
        return 0;
    }

    if (pos > elem_->size()) {
        (this->*pmf_)(pos);
    }
    return (*elem_)[pos-1];
}