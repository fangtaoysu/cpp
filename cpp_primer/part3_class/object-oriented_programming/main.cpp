/*
 * @Author: fangtao
 * @Date: 2024-08-18 23:49:26
 * @LastEditTime: 2024-08-22 15:58:26
 * @FilePath: /cpp/cpp_primer/part3_class/object-oriented_programming/main.cpp
 * @Description: 面向对象测试程序
 * 
 * Copyright (c) 2024 by fangtao, All Rights Reserved. 
 */

#include <vector>
#include <string>
#include <iostream>
#include <functional>
#include "./head_dir/bulk_quote.h"
#include "./head_dir/quote.h"


/**
 * @description: 使用动态绑定打印对象内容，并返回总价格
 * @param {ostream} &os 输出流
 * @param {Quote} &item Quote对象
 * @param {size_t} n 卖出数量
 * @return {double} ret 总价格
 */
double PrintTotal(std::ostream &os, const Quote &item, size_t n) {
    double ret = item.NetPrice(n);
    os << "ISBN: " << item.Isbn()
       << " # sold: " << n
       << " total due: " << ret << std::endl;
    return ret;
}

void Test() {
    BulkQuote bulk("abcd", 18.8, 10, 0.8);
    Quote base("abcd", 18.8);
    // 派生类向基类的转化只对指针或引用有效
    Quote* item_ptr = &bulk;

    // This calls BulkQuote::NetPrice because of dynamic binding
    double val = item_ptr->NetPrice(20);
    std::cout << val << std::endl;

    // This calls the Quote version of NetPrice
    // 基类向派生类的类型转化不存在隐式转化：在派生类向基类转化前，编译器会进行检查该操作是否合法
    // 使用static_cast<>会强制覆盖掉编译器的检查工作，从而完成转化
    double base_val = static_cast<Quote>(bulk).NetPrice(20);
    std::cout << base_val << std::endl;

    BulkQuote* bulk_ptr = &bulk;
    // 此处调用的都是派生类，因为动态绑定看的是最终绑定的对象，而不是指针或引用的类型
    PrintTotal(std::cout, *item_ptr, 20);  // Calls BulkQuote::NetPrice
    PrintTotal(std::cout, *bulk_ptr, 20);  // Calls BulkQuote::NetPrice

    // 强制对象转化，从而调用基类的函数
    PrintTotal(std::cout, static_cast<Quote>(bulk), 20); // Calls Quote::NetPrice
}

int main() {
    Test();
    return 0;
}