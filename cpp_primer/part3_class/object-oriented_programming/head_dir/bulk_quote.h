/*
 * @Author: fangtao
 * @Date: 2024-08-21 11:21:59
 * @LastEditTime: 2024-08-22 20:15:45
 * @FilePath: /cpp/cpp_primer/part3_class/object-oriented_programming/head_dir/bulk_quote.h
 * @Description: BulkQuote类的头文件
 * 
 * Copyright (c) 2024 by fangtao, All Rights Reserved. 
 */
#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H
#include "disc_quote.h"

class BulkQuote : public DiscQuote { // 继承
public:
    double NetPrice(std::size_t) const override;
    BulkQuote(/* args */) = default;
    BulkQuote(const std::string& book, double p, std::size_t count, double disc)
        : DiscQuote(book, p, count, disc) {
    }
};


#endif