/*
 * @Author: fangtao
 * @Date: 2024-08-27 09:56:18
 * @LastEditTime: 2024-08-27 20:50:16
 * @FilePath: /cpp/cpp_primer/part2_stl/text_query/head_dir/and_query.h
 * @Description: binary_query的派生类，返回它的两个运算对象分别出现的行的交集
 * 
 * Copyright (c) 2024 by fangtao, All Rights Reserved. 
 */
#ifndef AND_QUERY_H
#define AND_QUERY_H
#include "./query.h"
#include "./text_query.h"
#include "./query_result.h"
#include "./binary_query.h"
#include <set>


class AndQuery : public BinaryQuery {
    friend Query operator&(const Query&, const Query);
public:
    AndQuery(const Query& left, const Query& right) : BinaryQuery(left, right, "&") {
    }
    QueryResult Eval(const TextQuery&) const;
};

inline Query operator&(const Query& lhs, const Query& rhs);

Query operator&(const Query& lhs, const Query& rhs) {
    std::shared_ptr<QueryBase> tmp(new AndQuery(lhs, rhs));
    return Query(tmp);
}

#endif