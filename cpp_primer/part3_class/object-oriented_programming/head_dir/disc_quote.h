#ifndef DISC_QUOTE_H
#define DISC_QUOTE_H
#include "quote.h"

// 此处的public是派生访问说明符
// 派生访问说明符是控制派生类用户对基类的访问：private意味着用户不能通过派生类对象访问基类的public成员
// class默认private继承，struct默认public继承
class DiscQuote : public Quote {
// 此处的public是成员访问说明符，控制的是类对象对成员的访问
public:
    DiscQuote() = default;
    DiscQuote(const std::string& book, double price, std::size_t count, double discount)
        : Quote(book, price), quality_(count), discount_(discount) {
    }
    // 纯虚函数：指明当前函数没有实际意义
    // 含有纯虚函数的类是抽象基类，我们不能创建抽象基类的对象
    double NetPrice(std::size_t) const=0; // =0 纯虚函数标志
protected:
    std::size_t quality_ = 0; // 折扣适用的购买量
    double discount_ = 0.0;
};


#endif