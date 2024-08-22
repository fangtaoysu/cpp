/*
 * @Author: fangtao
 * @Date: 2024-08-21 11:21:59
 * @LastEditTime: 2024-08-22 15:10:56
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
    Quote(/* args */) = default;
    Quote(const std::string &book, double sales_price) : isbn_(book), price_(sales_price) {
    }
    virtual ~Quote() = default; // 对析构函数进行动态绑定
    std::string Isbn() const;
    virtual double NetPrice(std::size_t n) const; // 虚函数
};


#endif