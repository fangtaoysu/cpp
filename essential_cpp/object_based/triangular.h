#ifndef TRIANGULAR_H
#define TRIANGULAR_H

// #include <string>
#include <vector>
#include <iterator>
#include <iostream>
#include <ostream>
#include "triangular_iterator.h"

using namespace std;

class Triangular {
public:
    Triangular();
    Triangular(int len);
    Triangular(int len, int beg_pos);
    Triangular(const Triangular &rhs);
    // 泛化iterator的名字
    typedef TriangularIterator iterator;

    iterator begin() const {
        return iterator(beg_pos_);
    }

    iterator end() const {
        return iterator(beg_pos_+length_);
    }

    friend int iterator::operator*() const;
    // friend void TriangularIterator::check_integrity() const;
    // const 表明此成员函数不会改变类对象的内容
    int BegPos() const{return beg_pos_;}
    int Length() const{return length_;}
    int Elem(int pos) const {return kElems_[pos-1];};

    bool Next(int &val);
    void NextReset() {next_ = beg_pos_ - 1;}

    Triangular& Copy(const Triangular &rhs);
    // 重载输入输出
    friend ostream& operator<<(ostream &os, const Triangular &rhs);
    friend istream& operator>>(istream &is, Triangular &rhs);
    // static 方法对类的方法，而不是实例方法
    static bool IsElem(int);
    static void GenElements(int);
    static void GenElemsToValue(int);
    static void Display(int length, int beg_pos, ostream &os=cout);
    // 友元替代方案：开放私有成员的接口
    static int ElemSize() {return kElems_.size();}
    static int MaxElems() {return kMaxElems_;}

private:
    // std::string _name;
    int length_;
    int beg_pos_;
    // mutable 声明 next_不会破坏类对象的常量性，const修饰类对象后该属性是可变的
    mutable int next_;
    // static:唯一/可共享，可被类中所有实例对象访问
    static vector<int> kElems_;
    static int kMaxElems_;
};

#endif