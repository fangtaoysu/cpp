#ifndef NUM_SEQUENCE_H
#define NUM_SEQUENCE_H
#include <vector>
#include <iostream>
#include <ostream>

class NumSequence{
public:
    // 非虚函数在编译时完成解析，因此析构函数必须是虚函数
    virtual ~NumSequence() {
    }
    virtual int Elem(int pos) const=0; // 设为纯虚函数，在抽象类中无需实现
    virtual const char* WhatAmI() const=0;
    static int MaxElemes(); // 静态函数不用设为纯虚函数
    virtual std::ostream& Print(std::ostream &os=std::cout) const=0;
    friend std::ostream& operator<<(std::ostream &os, const NumSequence &ns);
    
protected:
    virtual void GenElems(int pos) const=0;
    bool CheckIntegrity(int pos, int size) const;
    const static int max_elems_ = 1024;
};
std::ostream& operator<<(std::ostream& os, const NumSequence& ns);
inline void Display(std::ostream &os, const NumSequence &ns, int pos) {
    os << "The element at position " << pos
       << " for the " << ns.WhatAmI() 
       << " sequence is " << ns.Elem(pos) << std::endl;
}

#endif