#ifndef LESS_THAN_H
#define LESS_THAN_H

#include <string>

template <typename elemType>
class LessThan {
public:
    LessThan(const elemType val): val_(val) {
    }
    // 基值的读写
    const elemType CompVal() const {
        return val_;
    }
    void CompVal(const elemType nval) {
        val_ = nval;
    }
    // 重载括号运算符实现 function object
    bool operator()(const elemType value) const;

private:
    const elemType val_;
};

template <typename elemType>
inline bool LessThan<elemType>::operator()(const elemType value) const {
    return value < val_;
}

#endif

template <typename elemType, typename Comp=LessThan<elemType> >
class LessThanPred{
public:
    LessThanPred(const elemType& val)
        :val_(val) {
    }
    bool operator() (const elemType& new_val) {
        return new_val < val_;
    }
    const elemType CompVal() const {
        return val_;
    }
    void CompVal(const elemType& new_val) const {
        val_ = new_val;
    }
private:
    elemType val_;
};

class StringLen {
public:
    bool operator() (const std::string &s1, const std::string &s2) {
        return s1.size() < s2.size();
    }
};