#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>


void WordCount() {
    std::map<std::string, size_t> word_count;
    std::set<std::string> exclude = {
        "The", "But", "And", "Or", "An", "A",
        "the", "but", "and", "or", "an", "a"
    };
    std::string word;
    while (std::cin >> word) {
        if (exclude.find(word) == exclude.end()) {
            ++word_count[word];
        }
    }
    // for (const std::pair<std::string, size_t> item : word_count) {
    //     std::cout << "first: " << item.first // key_type
    //               << "\tsecond: " << item.second << std::endl; // mappped_type
    // }

    for (auto map_it = word_count.cbegin(); map_it != word_count.cend(); ++map_it) {
        std::cout << "first: " << map_it->first // key_type
                  << "\tsecond: " << map_it->second << std::endl; // mappped_type
    }
    
}

std::pair<std::string, int> Process(std::vector<std::string> &v) {
    if (!v.empty()) {
        return {v.back(), v.back().size()}; // 最后一个元素
    } else {
        return std::pair<std::string, int>(); // 返回空值
    }
}

void TestPair() {
    std::vector<std::string> vec = {
        "a", "jifsdo", "jfjkdfhjkl"
    };
    auto p = Process(vec);
    std::cout << p.first << "\t" << p.second << std::endl; 
}

void TestInsert() {
    std::vector<int> ivec = {
        1, 3, 4, 56, 7
    };
    std::set<int> set1;
    set1.insert(ivec.cbegin(), ivec.cend());
    set1.insert({1, 4, 56, 67});

    std::map<std::string, size_t> word_count;
    std::pair<std::map<std::string, size_t>::iterator, bool> p = word_count.insert({"and", 1});
    std::cout << p.first->first << "\t"
              << p.first->second << "\t"
              << p.second << "\n";
    word_count.insert(std::make_pair("you", 2));
    word_count.insert(std::pair<std::string, size_t>("?", 3));
    word_count.insert(std::map<std::string, size_t>::value_type("hi", 4));
    std::for_each(word_count.cbegin(), word_count.cend(), [] (const std::pair<std::string, size_t> item) {
        std::cout << item.first << "\t" << item.second << std::endl;
    });
}

void TestFind() {
    std::multimap<std::string, std::string> authors;
    authors.insert({"Lisa", "find you"});
    authors.insert({"Lisa", "and you"});
    authors.insert({"Lisa", "with you"});
    authors.insert({"Lisa", "can you"});
    std::string search_item("Lisa");
    // 查找
    // 方案1：find()
    std::cout << "find()\n";
    auto entries = authors.count(search_item);
    auto iter = authors.find(search_item);
    while (entries) {
        std::cout << iter->first << std::endl; // first 是 key
        std::cout << iter->second << std::endl; // second 是value
        ++iter;
        --entries;
    }
    // 方案2：lower_bound() upper_bound()
    std::cout << "lower_bound() upper_bound()\n";
    for (auto beg = authors.lower_bound(search_item); beg != authors.upper_bound(search_item); ++beg) {
        std::cout << beg->second << std::endl;
    }
    // 方案3：equal_range
    std::cout << "equal_range()\n";
    for (auto pos = authors.equal_range(search_item); pos.first != pos.second; ++pos.first) {
        std::cout << pos.first->second << std::endl;
    }
}

void TestUnordered() {
    std::unordered_map<std::string, size_t> word_count;
    std::string word;
    while (std::cin >> word) {
        ++word_count[word];
    }
    for (const auto &w : word_count) {
        std::cout << w.first << "\t" << w.second << std::endl;
    }
    // 通操作
    std::cout << word_count.bucket_count() << std::endl;
    std::cout << word_count.max_bucket_count() << std::endl;
    std::cout << word_count.bucket_size(1) << std::endl; // 第1个通中有多少个元素
    // 哈希策略
    std::cout << word_count.load_factor() << std::endl; // 每个桶平均元素数量
    std::cout << word_count.max_load_factor() << std::endl;
}

int main() {
    // WordCount();
    // TestPair();
    // TestInsert();
    // TestFind();
    TestUnordered();


    return 0;
}