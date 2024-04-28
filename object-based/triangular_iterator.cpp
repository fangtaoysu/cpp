#include "triangular.h"
// #include <iterator_overflow.h>


inline bool TriangularIterator::operator==(const TriangularIterator &rhs) const {
    return this->index_ == rhs.index_;
}

inline bool TriangularIterator::operator!=(const TriangularIterator &rhs) const {
    return !(*this == rhs);
}

inline int TriangularIterator::operator*() const {
    CheckIntegrity();
    return Triangular::kElems_[index_];
}

inline void TriangularIterator::CheckIntegrity() const {
    // if (index_ >= Triangular::max_elems_()) {
    //     throw iterator_overflow();
    // }

    if (index_ >= Triangular::ElemSize()) {
        Triangular::GenElements(index_+1);
    }
}

inline TriangularIterator& TriangularIterator::operator++() {
    /** ++it
    */
    ++index_;
    CheckIntegrity();
    return *this;
}

inline TriangularIterator& TriangularIterator::operator++(int) {
    /** it++
    */
   TriangularIterator tmp = *this;
   ++index_;
   CheckIntegrity();
   return tmp;
}