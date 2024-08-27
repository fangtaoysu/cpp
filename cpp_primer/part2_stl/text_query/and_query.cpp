/*
 * @Author: fangtao
 * @Date: 2024-08-27 09:56:18
 * @LastEditTime: 2024-08-27 17:41:28
 * @FilePath: /cpp/cpp_primer/part2_stl/text_query/and_query.cpp
 * @Description: 
 * 
 * Copyright (c) 2024 by fangtao, All Rights Reserved. 
 */
/*
 * @Author: fangtao
 * @Date: 2024-08-27 09:56:18
 * @LastEditTime: 2024-08-27 16:48:52
 * @FilePath: /cpp/cpp_primer/part2_stl/text_query/and_query.cpp
 * @Description: 
 * 
 * Copyright (c) 2024 by fangtao, All Rights Reserved. 
 */
#include "./head_dir/and_query.h"
#include <algorithm>

QueryResult AndQuery::Eval(const TextQuery& text) const {
    auto left = lhs_.Eval(text);
    auto right = rhs_.Eval(text);
    auto res_lines = std::make_shared<std::set<line_no_>>();
    // 取交集
    std::set_intersection(left.begin(), left.end(), right.begin(), right.end(), std::inserter(*res_lines, res_lines->begin()));
    return QueryResult(Rep(), res_lines, left.GetFile());
} 