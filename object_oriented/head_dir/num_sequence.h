#ifndef NUM_SEQUENCE_H
#define NUM_SEQUENCE_H
#include <vector>
#include <iostream>
#include <ostream>


template <int length, int beg_pos>
class NumSequence{
public:
    // 非虚函数在编译时完成解析，因此析构函数必须是虚函数
    virtual ~NumSequence() {
    }
    int Elem(int pos) const; // 使用虚函数机制
    std::ostream& Print(std::ostream &os=std::cout) const;
    /**
     * 复用WhatAmI函数的两种方案：
     *  1. 使用字符串成员
     *  2. 使用typeid运算符实现运行时类型鉴定
    */
    const char* WhatAmI() const; 
    // int Length() {
    //     return length_;
    // }
    // int BegPos() {
    //     return beg_pos_;
    // }
    static int MaxElems() { // 静态函数不用设为纯虚函数
        return 64;
    } 
    
protected: 
    virtual void GenElems(int pos) const=0;
    bool CheckIntegrity(int pos, int size) const;
    // NumSequence(int len=1, int bp=1, std::vector<int> *pe=0)
    //     : length_(len), beg_pos_(bp), pelems_(pe) {
    // }
    NumSequence(std::vector<int> *pe) : pelems_(pe){
    };
    // int length_;
    // int beg_pos_;
    std::vector<int> * pelems_;
};




#endif