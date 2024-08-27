#include "./head_dir/not_query.h"


QueryResult NotQuery::Eval(const TextQuery& text) const {
    auto result = query_.Eval(text);
    auto res_lines = std::make_shared<std::set<line_no_>>();
    auto beg = result.begin();
    auto end = result.end();
    // 获取总行数
    auto size = result.GetFile()->size();
    for (size_t n = 0; n != size; ++n) {
        // 如果该行不在query_查询的结果中
        if (beg == end || *beg != n) { // 添加
            res_lines->insert(n);
        } else if (beg != end) { // 继续遍历
            ++beg;
        }
    }
    return QueryResult(Rep(), res_lines, result.GetFile());
}