#ifndef LIB_MAT_H
#define LIB_MAT_H
#include <iostream>


class LibMat {
public:
    LibMat() {
        std::cout << "LibMat::LibMat() default constructor\n";
    }
    virtual ~LibMat() {
        std::cout << "LibMat::~LibMat() destructor\n";
    }
    virtual void Print() const {
        std::cout << "LibMat::Print() -- I am LibMat object\n";
    }

private:

};

#endif