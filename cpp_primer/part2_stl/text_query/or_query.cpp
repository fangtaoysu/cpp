#include "./head_dir/or_query.h"


QueryResult OrQuery::Eval(const TextQuery& text) const {
    auto left = lhs_.Eval(text);
    auto right = rhs_.Eval(text);
    auto res_lines = std::make_shared<std::set<line_no_>>(left.begin(), left.end());
    res_lines->insert(right.begin(), right.end());
    return QueryResult(Rep(), res_lines, left.GetFile());
}


