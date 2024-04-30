#ifndef LIB_MAT_H
#define LIB_MAT_H


using namespace std;
class LibMat {
public:
    LibMat() {
        cout << "LibMat::LibMat() default constructor\n";
    }
    virtual ~LibMat() {
        cout << "LibMat::~LibMat() destructor\n";
    }
    virtual void Print() const {
        cout << "LibMat::Print() -- I am LibMat object\n";
    }

private:

};

#endif