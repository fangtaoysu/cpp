/*
 * @Author: fangtao
 * @Date: 2024-08-27 10:00:57
 * @LastEditTime: 2024-08-27 21:13:19
 * @FilePath: /cpp/cpp_primer/part2_stl/text_query/head_dir/binary_query.h
 * @Description: query_base派生出的另一个抽象基类，表示有两个运算对象的查询
 * 
 * Copyright (c) 2024 by fangtao, All Rights Reserved. 
 */
#ifndef BINARY_QUERY_H
#define BINARY_QUERY_H
#include <string>
#include "./query.h"


class BinaryQuery : public QueryBase {
protected:
    BinaryQuery(const Query& lhs, const Query& rhs, std::string s) : lhs_(lhs), rhs_(rhs), op_name_(s) {
    }
    std::string Rep() const {
        std::string res = "(" + lhs_.Rep() + ") " + op_name_ + " (" + rhs_.Rep() + ")";
        return res;
    }
    Query lhs_, rhs_;
    std::string op_name_;
};


#endif