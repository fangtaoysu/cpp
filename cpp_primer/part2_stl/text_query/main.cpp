/*
 * @Author: fangtao
 * @Date: 2024-08-07 09:05:30
 * @LastEditTime: 2024-08-27 21:57:25
 * @FilePath: /cpp/cpp_primer/part2_stl/text_query/main.cpp
 * @Description: Query继承图
 * QueryBase         --- friend Query
 * |- NotQuery       --- friend operator~
 * |- WordQuery      --- friend Query 
 * |- BinaryQuery     
 *      |- AndQuery  --- friend operator&
 *      |- OrQuery   --- friend operator|
 * 
 * Query             --- friend operator~ operator| operator&
 * QueryResult       --- friend Print
 * 设计思路：要设计一个支持使用运算符的查找程序，可以考虑在原有基础上添加重载运算符，也可以设计一个query家族
 *     但是在原有基础上（TextQuery)重载运算符，相较于另一种方法，实现起来较为复杂
 *     如果做一个虚基类作为查询父类，其他方式的查询成员函数（Eval）都是基于TextQuery类的一个封装，再实现
 *     查询结果类（QueryResult）的迭代，和GetFile(获取(file_)接口，其他部分就很好实现了。
 *     NotQuery使用QueryResult的迭代实现
 *     AndQuery使用<algorithm>的insert实现
 *     OrQuery使用set的set_intersection实现
 * Copyright (c) 2024 by fangtao, All Rights Reserved. 
 */
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include "./head_dir/query_base.h"
#include "./head_dir/not_query.h"
#include "./head_dir/and_query.h"
#include "./head_dir/or_query.h"
#include "./head_dir/binary_query.h"
#include "./head_dir/query.h"
#include "./head_dir/text_query.h"
#include "./head_dir/word_query.h"
#include "./head_dir/query_result.h"

int WordCount(std::string& sentence, const std::string word) {
    int res = 0;
    std::string::iterator it = sentence.begin();
    int i = 0;
    while ((it = std::find(it, sentence.end(), word[i])) != sentence.end()) {
        while (i < word.size() && *it++ == word[i]) {
            ++i;
        }
        if (i >= word.size()) {
            ++res;
        }
        i = 0;
    }
    return res;
}

void QueryText(const std::string& file_name, const std::string& word) {
    // 中文单词检索
    if (word.size() == 0) {
        return;
    }
    int line_number = 1;
    int word_count = 0;
    std::ifstream f(file_name);
    std::string line;
    while (f >> line) {
        int line_count = WordCount(line, word);
        if (line_count != 0) {
            std::cout << "line:(" << line_number
                      << ", " << line_count
                      << ")\t" << line << std::endl;
        }
        word_count += line_count;
        ++line_number;
    }
    std::cout << word << "共计：" << word_count << std::endl;
}

std::ostream& Print(std::ostream &os, const QueryResult &qr) {
    os << qr.word_ << " occurs "
       << qr.lines_->size() << " "
       << (qr.lines_->size() > 1 ? "times" : "time") << std::endl;
    for (auto num : *qr.lines_) {
        os << "\t(line " << num + 1
           << ") " << *(qr.file_->begin() + num) << std::endl;
    }
    return os;
}

void RunQueries(std::ifstream &infile) {
    TextQuery tq(infile);
    while (true) {
        std::cout << "enter word to look for, or q to quit: ";
        std::string s;
        if (!(std::cin >> s) || s == "q") {
            break;
        }
        Print(std::cout, tq.Query(s)) << std::endl;
    }
}

void TestQueryResult() {
    // std::string file_name = "./老人与海.txt";
    // std::string word = "老人";
    // QueryText(file_name, word);

    std::string file_name = "./story.txt";
    std::ifstream ifs(file_name);
    RunQueries(ifs);
}

std::ostream& operator<<(std::ostream& os, const Query& query) {
    return os << query.Rep();
}

void TestQuery() {
    std::ifstream ifs("./story.txt");
    TextQuery tq(ifs);
    Query not_query = ~Query("man");
    std::cout << not_query << std::endl;
    Query and_query = Query("and") & Query("but");
    std::cout << and_query << std::endl;
    Query or_query = Query("and") | Query("but");
    std::cout << or_query << std::endl;
    Print(std::cout, not_query.Eval(tq)) << std::endl;
    Print(std::cout, and_query.Eval(tq)) << std::endl;
    Print(std::cout, or_query.Eval(tq)) << std::endl;
}

int main() {
    // TestQueryResult();
    TestQuery();
}