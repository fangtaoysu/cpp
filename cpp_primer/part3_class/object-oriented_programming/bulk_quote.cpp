/*
 * @Author: fangtao
 * @Date: 2024-08-21 11:21:41
 * @LastEditTime: 2024-08-22 20:17:50
 * @FilePath: /cpp/cpp_primer/part3_class/object-oriented_programming/bulk_quote.cpp
 * @Description: BulkQuote类的函数定义
 * 
 * Copyright (c) 2024 by fangtao, All Rights Reserved. 
 */
#include "./head_dir/bulk_quote.h"

double BulkQuote::NetPrice(std::size_t n) const {
    if (n >= DiscQuote::quality_) {        
        return n * DiscQuote::discount_ * Quote::price_;
    } else {
        return this->Quote::NetPrice(n); // 派生类虚函数调用基类版本时，使用作用域运算符回避虚函数机制
    }
}

BulkQuote::~BulkQuote() {
    std::cout << "~BulkQuote" << std::endl;
}