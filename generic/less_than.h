#ifndef LESS_THAN_H
#define LESS_THAN_H

class LessThan {
public:
    LessThan(int val): val_(val) {
    }

    // 基值的读写
    int CompVal() const {
        return val_;
    }
    void CompVal(int nval) {
        val_ = nval;
    }
    // 重载括号运算符实现 function object
    bool operator()(int value) const;

private:
    int val_;
};

inline bool LessThan::operator()(int value) const {
    return value < val_;
}

#endif