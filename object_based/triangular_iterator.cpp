#include "triangular.h"
#include "iterator_overflow.h"


bool TriangularIterator::operator==(const TriangularIterator &rhs) const {
    return this->index_ == rhs.index_;
}

bool TriangularIterator::operator!=(const TriangularIterator &rhs) const {
    return !(*this == rhs);
}

int TriangularIterator::operator*() const {
    CheckIntegrity();
    return Triangular::kElems_[index_];
}

void TriangularIterator::CheckIntegrity() const {
    if (index_ >= Triangular::MaxElems()) {
        IteratorOverflow ex(index_, Triangular::MaxElems());
        throw ex;
    }

    if (index_ >= Triangular::ElemSize()) {
        Triangular::GenElements(index_+1);
    }
}

TriangularIterator& TriangularIterator::operator++() {
    /** ++it
    */
    ++index_;
    CheckIntegrity();
    return *this;
}

TriangularIterator TriangularIterator::operator++(int) {
    /** it++
    */
   TriangularIterator tmp = *this;
   ++index_;
   CheckIntegrity();
   return tmp;
}