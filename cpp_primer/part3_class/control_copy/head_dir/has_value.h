#ifndef HAS_VALUE_H
#define HAS_VALUE_H
// 行为类型值的类
#include <string>

class HasValue {
public:
    HasValue(const std::string &s = std::string())
        : ps_(new std::string(s)), i_(0) {
    }
    // 拷贝构造函数
    HasValue(const HasValue& rhs) 
        : ps_(new std::string(*rhs.ps_)), i_(rhs.i_) {
    }

    // 拷贝赋值运算符
    HasValue& operator=(const HasValue& rhs);
    // 1.如果需要定义析构函数，则必须定义拷贝构造函数和拷贝赋值运算符
    // 2.如果需要拷贝构造函数，则需要拷贝赋值运算符，反之亦然
    ~HasValue() {
        delete ps_;
    }
private:
    std::string* ps_;
    int i_;
};

#endif