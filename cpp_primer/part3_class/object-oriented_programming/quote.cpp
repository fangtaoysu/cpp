/*
 * @Author: fangtao
 * @Date: 2024-08-21 11:21:41
 * @LastEditTime: 2024-08-22 15:56:17
 * @FilePath: /cpp/cpp_primer/part3_class/object-oriented_programming/quote.cpp
 * @Description: Quote虚基类的实现文件
 * 
 * Copyright (c) 2024 by fangtao, All Rights Reserved. 
 */
#include "./head_dir/quote.h"


std::string Quote::Isbn() const {
    return isbn_;
}

// virtual关键字只能出现在类内部的声明中，而不能出现类外部的函数定义中
double Quote::NetPrice(std::size_t n) const {
    return n * price_;
}
