/*
 * @Author: fangtao
 * @Date: 2024-08-24 18:57:08
 * @LastEditTime: 2024-08-26 22:38:06
 * @FilePath: /cpp/cpp_primer/part3_class/object-oriented_programming/head_dir/basket.h
 * @Description: basket类接口，实现对quote类的指针管理
 * 
 * Copyright (c) 2024 by fangtao, All Rights Reserved. 
 */
#ifndef BASKET_H
#define BASKET_H
#include <memory>
#include <set>
#include <iostream>
#include "quote.h"

class Quote;
class Basket
{
private:
    /* data */
    // 为shared_ptr提供比较运算符
    static bool compare(const std::shared_ptr<Quote> &lhs, const std::shared_ptr<Quote> &rhs) {
        return lhs->Isbn() < rhs->Isbn();
    }
    std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items_{compare};
public:
    // void AddItem(const std::shared_ptr<Quote> &sale) {
    //     items_.insert(sale);
    // }
    // 让AddItem接受Quote对象，从而达到隐藏指针的目的，而不是shared_ptr；
    void AddItem(const Quote& sale) {
        items_.insert(std::shared_ptr<Quote>(sale.clone()));
    }
    void AddItem(Quote&& sale) {
        items_.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
    }
    
    double TotalReceipt(std::ostream&) const;

};

#endif