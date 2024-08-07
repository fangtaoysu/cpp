#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include "./text_query.h"
#include "./query_result.h"

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

int main() {
    // std::string file_name = "./老人与海.txt";
    // std::string word = "老人";
    // QueryText(file_name, word);

    std::string file_name = "./story.txt";
    std::ifstream ifs(file_name);
    RunQueries(ifs);
}