#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;


struct PersonInfo {
    std::string name;
    std::vector<std::string> phones;
};

bool Valid(const std::string &numbers) {
    for (const auto &ch : numbers) {
        if (ch < '0' || ch > '9') {
            return false;
        }
    }
    return true;
}

std::string Format(const std::string &numbers) {
    std::string formatted_numbers = "\n|---" + numbers;
    return formatted_numbers;
}

void PrintInfo(std::vector<PersonInfo> people) {
    cout << "Print all person info:\n";
    // for (auto person : people) {
    //     cout << "name: " << person.name << endl;
    //     for (auto phone : person.phones) {
    //         cout << "|--phone: " << phone << endl;
    //     }
    //     cout << endl;
    // }
    for (const auto &person : people) {
        std::ostringstream formatted, bad_nums;
        for (const auto &nums : person.phones) { // 检验并格式化号码
            if (!Valid(nums)) {
                bad_nums << " " << nums;
            } else {
                formatted << " " << Format(nums);
            }
        }
        if (bad_nums.str().empty()) { // 打印信息
            cout << person.name << " " 
                 << formatted.str() << endl;
        } else {
            std::cerr << "input error: " << person.name
                      << " invalid number(s) " << bad_nums.str() << endl;
        }
    }
}

void SaveInfo() {
    std::string line, word;
    std::vector<PersonInfo> people;
    std::istringstream record;
    std::ifstream is("file1.txt");
    while (getline(is, line)) {
        PersonInfo info;
        // 将读到的以空格分隔的字符串赋值给istringstream对象 line = "fangtao 123 456 789";
        // std::istringstream record(line);
        record.str(line);
        record >> info.name;
        while (record >> word) {
                info.phones.push_back(word);
        }
        people.push_back(info);
        record.clear();
    }
    PrintInfo(people);
}

void ReadFileByWord(std::vector<std::string> &word_vec, const std::string &file_name) {
    // 以词为单位读文件
    std::ifstream is(file_name);
    if (is.is_open()) {
        std::string line, word;
        while (getline(is, line)) {
            std::istringstream record(line);
            while (record >> word) {
                word_vec.push_back(word);
            }
        }
    }
}

int main() {
    SaveInfo();
    // std::vector<std::string> word_vec;
    // ReadFileByWord(word_vec, "file1.txt");
    // for (auto word : word_vec) {
    //     cout << word << endl;
    // }
    return 0;
}