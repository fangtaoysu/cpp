#include "./text_query.h"
#include <sstream>

TextQuery::TextQuery(std::ifstream& ifs) 
    : file_(new std::vector<std::string>) {
    std::string text;
    while (std::getline(ifs, text)) { // 处理每行
        file_->push_back(text);
        int line_number = file_->size() - 1;
        std::istringstream line(text);
        std::string word;
        while (line >> word) { // 处理每个单词
            // shared_ptr类型
            auto &lines = wm_[word];
            if (!lines) { // 本行首次遇到该单词，则写入行号
                lines.reset(new std::set<line_no>);
            }
            lines->insert(line_number);
        }
    }
}

QueryResult TextQuery::Query(const std::string &word) const {
    static std::shared_ptr<std::set<line_no>> no_data(new std::set<line_no>);
    auto loc = wm_.find(word);
    if (loc == wm_.end()) {
        return QueryResult(word, no_data, file_);
    } else {
        return QueryResult(word, loc->second, file_);
    }
}