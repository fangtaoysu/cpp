/*
 * @Author: fangtao
 * @Date: 2024-08-27 09:50:14
 * @LastEditTime: 2024-08-27 20:24:33
 * @FilePath: /cpp/cpp_primer/part2_stl/text_query/head_dir/query_base.h
 * @Description: 查询类的抽象基类
 * 
 * Copyright (c) 2024 by fangtao, All Rights Reserved. 
 */
#ifndef QUERY_BASE_H
#define QUERY_BASE_H
#include "./text_query.h"
#include "./query_result.h"
#include <string>

class QueryBase {
    friend class Query;
private:
    /* data */
    // 返回与当前Query匹配QueryResult
    virtual QueryResult Eval(const TextQuery&) const = 0;
    // 查询字符串
    virtual std::string Rep() const = 0;
protected:
    using line_no_ = TextQuery::line_no; // 用于Eval函数
    virtual ~QueryBase() = default;
};



#endif