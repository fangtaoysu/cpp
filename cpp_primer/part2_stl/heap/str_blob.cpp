#include "./str_blob.h"
#include <memory>
#include <stdexcept>
#include <iostream>

StrBlob::StrBlob()
    : data_(std::make_shared<std::vector<std::string>>()) {
}

StrBlob::StrBlob(std::initializer_list<std::string> il)
    : data_(std::make_shared<std::vector<std::string>>(il)) {
}

void StrBlob::Check(size_type i, const std::string &msg) const {
    if (i >= data_->size()) {
        throw std::out_of_range(msg);
    }
}

std::string& StrBlob::Front() const{
    // 检查vector是否为空
    Check(0, "Front on emptyStrBlob");
    return data_->front();
}

std::string& StrBlob::Back() const{
    Check(0, "Back on empty StrBlob");
    return data_->back();
}

void StrBlob::PopBack() {
    Check(0, "PopBack on empty StrBlob");
    data_->pop_back();
}

void StrBlob::Print() const{
    for (auto &val : *data_) {
        std::cout << val << "\t";
    }
    std::cout << std::endl;
}