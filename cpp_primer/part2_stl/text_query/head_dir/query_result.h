/*
 * @Author: fangtao
 * @Date: 2024-08-07 20:44:26
 * @LastEditTime: 2024-08-27 17:41:24
 * @FilePath: /cpp/cpp_primer/part2_stl/text_query/head_dir/query_result.h
 * @Description: 
 * 
 * Copyright (c) 2024 by fangtao, All Rights Reserved. 
 */
#ifndef QUERY_RESULT_H
#define QUERY_RESULT_H
#include <string>
#include <vector>
#include <set>
#include <memory>

class QueryResult{
friend std::ostream& Print(std::ostream&, const QueryResult&);
public:
    using line_no = std::vector<std::string>::size_type;
    QueryResult(std::string s, std::shared_ptr<std::set<line_no>> p, std::shared_ptr<std::vector<std::string>> f)
        : word_(s), lines_(p), file_(f) {
    }
    using ResultIter = std::set<line_no>::iterator;

    ResultIter begin() {
        return lines_->begin();
    }
    ResultIter end() {
        return lines_->end();
    }
    std::shared_ptr<std::vector<std::string>> GetFile() {
        return file_;
    }
    
private:
    std::string word_;
    std::shared_ptr<std::set<line_no>> lines_;
    std::shared_ptr<std::vector<std::string>> file_;
};

#endif