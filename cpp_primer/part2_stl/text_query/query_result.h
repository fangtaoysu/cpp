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
private:
    std::string word_;
    std::shared_ptr<std::set<line_no>> lines_;
    std::shared_ptr<std::vector<std::string>> file_;
};

#endif