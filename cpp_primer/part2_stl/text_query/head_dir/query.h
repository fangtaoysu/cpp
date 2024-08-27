/*
 * @Author: fangtao
 * @Date: 2024-08-27 10:04:21
 * @LastEditTime: 2024-08-27 21:09:08
 * @FilePath: /cpp/cpp_primer/part2_stl/text_query/head_dir/query.h
 * @Description: query接口类，负责隐藏整个继承体系
 * 
 * Copyright (c) 2024 by fangtao, All Rights Reserved. 
 */
#ifndef QUERY_H
#define QUERY_H
#include <string>
#include <memory>
#include <set>
#include "./query_base.h"
#include "./query_result.h"
#include "./text_query.h"
#include "./word_query.h"

class Query {
    friend Query operator~(const Query&);
    friend Query operator&(const Query&, const Query&);
    friend Query operator|(const Query&, const Query&);
private:
    /* data */
    Query(std::shared_ptr<QueryBase> query) : q_(query) {
    }
    std::shared_ptr<QueryBase> q_;
public:
    Query(const std::string&);
    QueryResult Eval(const TextQuery &t) const {
        return q_->Eval(t);
    }
    std::string Rep() const {
        return q_->Rep();
    }
};

// std::shared_ptr<WordQuery> ptr = new WordQuery(s);
// q_(ptr); // 派生类指针隐式转化为基类指针
inline Query::Query(const std::string& s) : q_(new WordQuery(s)) {
}


#endif