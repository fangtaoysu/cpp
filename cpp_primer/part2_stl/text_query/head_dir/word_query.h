/*
 * @Author: fangtao
 * @Date: 2024-08-27 09:56:18
 * @LastEditTime: 2024-08-27 21:09:42
 * @FilePath: /cpp/cpp_primer/part2_stl/text_query/head_dir/word_query.h
 * @Description: 用于查找一个给定的单词
 * 
 * Copyright (c) 2024 by fangtao, All Rights Reserved. 
 */
#ifndef WORD_QUERY_H
#define WORD_QUERY_H
#include "./query_base.h"
#include "./query_result.h"
#include "./text_query.h"
#include <string>


class WordQuery : public QueryBase {
    friend class Query;
    WordQuery(const std::string &s) : query_word_(s) {
    }
    // 根据传入的单词，查询封装好的结果
    QueryResult Eval(const TextQuery &t) const {
        return t.Query(query_word_);
    }
    // 返回需要查询的单词
    std::string Rep() const {
        return query_word_;
    }
    std::string query_word_; // 要查找的单词
};


#endif