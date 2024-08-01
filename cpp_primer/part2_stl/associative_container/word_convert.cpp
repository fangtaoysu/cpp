#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <fstream>
#include <sstream>
#include <system_error>


std::map<std::string, std::string> BuildMap(std::ifstream &map_file);
const std::string& Transform(const std::string &s, const std::map<std::string, std::string> &m);
void WordTransform(std::ifstream &map_file, std::ifstream &input);

int main() {
    std::string input = "input.txt";
    std::string rule = "rule.txt";
    std::ifstream rule_ifs(rule);
    std::ifstream input_ifs(input);
    WordTransform(rule_ifs, input_ifs);
    return 0;
}

void WordTransform(std::ifstream &map_file, std::ifstream &input) {
    // 读取转化规则
    auto trans_map = BuildMap(map_file);
    std::string text;
    while (std::getline(input, text)) {
        std::istringstream stream(text);
        std::string word;
        bool first_word = true;
        while (stream >> word) {
            if (first_word) {
                first_word = false;
            } else {
                std::cout << " ";
            }
            std::cout << Transform(word, trans_map);
        }
        std::cout << std::endl;
    }
}

std::map<std::string, std::string> BuildMap(std::ifstream &map_file) {
    std::map<std::string, std::string> trans_map;
    std::string key, value;
    while (map_file >> key &&  std::getline(map_file, value)) {
        if (value.size() > 1) {
            // trans_map[key] = value.substr(1);
            trans_map.insert({key, value.substr(1)});
        } else {
            throw std::runtime_error("no rule for " + key);
        }
    }
    return trans_map;
}

// 函数返回值是const的引用意味着此返回值在之后都不可修改
const std::string& Transform(const std::string &s, const std::map<std::string, std::string> &m) {
    auto map_it = m.find(s);
    if (map_it != m.cend()) {
        return map_it->second;
    } else {
        return s;
    }
}