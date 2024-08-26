/*
 * @Author: fangtao
 * @Date: 2024-08-21 11:21:59
 * @LastEditTime: 2024-08-26 22:27:40
 * @FilePath: /cpp/cpp_primer/part3_class/object-oriented_programming/head_dir/quote.h
 * @Description: Quote虚基类的头文件
 * 
 * Copyright (c) 2024 by fangtao, All Rights Reserved. 
 */
#ifndef QUOTE_H
#define QUOTE_H
#include <string>
#include <iostream>

class Quote {
private:
    /* data */
    std::string isbn_; // 书籍的ISBN编号
protected:
    double price_ = 0.0; // 表示不打折的价格
public:
    Quote(/* args */) {
        std::cout << "Quote" << std::endl;
    }
    Quote(const std::string &book, double sales_price) : isbn_(book), price_(sales_price) {
    } 
    // 如果我们删除的是一个指向派生类对象的基类指针，则需要虚析构函数
    virtual ~Quote(); // 对析构函数进行动态绑定
    // 当析构函数是虚函数的时候，默认不会有合成函数，此时需要对合成函数进行显示声明
    Quote(const Quote&) = default;
    Quote& operator=(const Quote&) = default;

    Quote(Quote&&) = default;
    Quote& operator=(Quote&&) = default;

    // 该虚函数返回当前对象的一份动态分配的拷贝
    virtual Quote* clone() const & { // 拷贝
        return new Quote(*this);
    }
    virtual Quote* clone() && { // 移动
        return new Quote(std::move(*this));
    }
    
    std::string Isbn() const;
    virtual double NetPrice(std::size_t n) const; // 虚函数
};


#endif