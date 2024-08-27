/*
 * @Author: fangtao
 * @Date: 2024-08-27 09:56:18
 * @LastEditTime: 2024-08-27 20:41:03
 * @FilePath: /cpp/cpp_primer/part2_stl/text_query/head_dir/not_query.h
 * @Description: query_base的派生类，查询query运算对象没有出现的行的集合
 * 
 * Copyright (c) 2024 by fangtao, All Rights Reserved. 
 */
#ifndef NOT_QUERY_H
#define NOT_QUERY_H
#include "./query.h"
#include "./query_base.h"
#include "./query_result.h"
#include "./text_query.h"
#include <string>


class NotQuery : public QueryBase {
    friend Query operator~(const Query&);
    NotQuery(const Query &q) : query_(q) {
    }
    // 返回带运算符的查询字符串
    std::string Rep() const {
        return "~(" + query_.Rep() + ")";
    }
    QueryResult Eval(const TextQuery&) const;
    Query query_;
};

// 动态分配一个新的NotQuery对象
inline Query operator~(const Query &operand);
// 是否声明为成员函数，则需要考虑其是否与需要与其他类型做该操作符运算
// 如果声明为成员函数，则参数个数-1（this）
Query operator~(const Query &operand) {
    // 与下面等价
    std::shared_ptr<QueryBase> tmp(new NotQuery(operand));
    return Query(tmp);
    // 最后进行隐式转化
    // return std::shared_ptr<QueryBase>(new NotQuery(operand));
}


#endif