#ifndef TRIANGULAR_ITERATOR_H
#define TRIANGULAR_ITERATOR_H

class TriangularIterator {
public:
    TriangularIterator(int index) : index_(index - 1){}
    bool operator==(const TriangularIterator&) const;
    bool operator!=(const TriangularIterator&) const;
    int operator*() const;
    TriangularIterator& operator++(); // ++it;
    TriangularIterator& operator++(int); // it++;

private:
    void CheckIntegrity() const;
    int index_;
};

#endif