#ifndef NUM_SEQUENCE_H
#define NUM_SEQUENCE_H
#include <vector>

class NumSequence{
public:
    typedef void (NumSequence::*PtrType)(int);

    void Fibonacci(int);
    void Pell(int);
    void Lucas(int);
    void Trinagular(int);
    void Sequare(int);
    void Pentagonal(int);
    int Elem(int);

private:
    vector<int>* elem_; // 指向目前所用的vector
    PtrType pmf_; // 指向目前所用的算法
    static const int kNumSeq_ = 7;
    static PtrType kFuncTbl_[kNumSeq_];
    // >>中间加入空格防止编译器识别成输出
    static vector<vector<int> > kSeq_;
};

#endif