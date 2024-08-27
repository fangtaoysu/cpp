#ifndef TEXT_QUERY_H
#define TEXT_QUERY_H
#include "./query_result.h"
#include <vector>
#include <map>
#include <set>
#include <string>
#include <memory>
#include <fstream>


class QueryResult;
class TextQuery {
public:
    using line_no = std::vector<std::string>::size_type;
    TextQuery(std::ifstream&);
    QueryResult Query(const std::string&) const;
private:
    std::shared_ptr<std::vector<std::string>> file_;
    // (查询字符, 行号)
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm_;

};

#endif