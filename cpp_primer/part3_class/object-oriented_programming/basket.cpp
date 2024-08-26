/*
 * @Author: fangtao
 * @Date: 2024-08-24 18:57:00
 * @LastEditTime: 2024-08-26 22:47:33
 * @FilePath: /cpp/cpp_primer/part3_class/object-oriented_programming/basket.cpp
 * @Description: 实现basket类
 * 
 * Copyright (c) 2024 by fangtao, All Rights Reserved. 
 */
#include "./head_dir/basket.h"

double PrintTotal(std::ostream &os, const Quote &item, size_t n);
double Basket::TotalReceipt(std::ostream &os) const {
    // 逐项打印basket类中包含的Quote对象，并返回总价
    double sum = 0.0;
    for (auto iter = items_.cbegin(); iter != items_.cend(); iter = items_.upper_bound(*iter)) {
        sum += PrintTotal(os, **iter, items_.count(*iter));
    }
    os << "Total Sale: " << sum << std::endl;
    return sum;
}