#ifndef STR_BLOB_H
#define STR_BLOB_H
#include <vector>
#include <string>
#include <memory>
#include <initializer_list>
#include "./str_blob_ptr.h"

class StrBlobPtr; // 友元函数的前置声明
class StrBlob {
public:
    friend class StrBlobPtr;
    typedef std::vector<std::string>::size_type size_type;
    StrBlobPtr begin() {
        return StrBlobPtr(*this);
    }
    StrBlobPtr end() {
        auto ret = StrBlobPtr(*this, data_->size());
        return ret;
    }
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    size_type Size() const {
        return data_->size();
    }
    bool Empty() const {
        return data_->empty();
    }
    void PushBack(const std::string &t) {
        data_->push_back(t);
    }
    void Print() const;
    void PopBack();
    std::string& Front() const;
    std::string& Back() const;

private:
    // 相比于static，shared_ptr可以确保 当调用一个销毁对象的data_的函数后，
    // 如果还存在其他对象指向这个vector，那么这个vector因为调用这个函数而被销毁
    std::shared_ptr<std::vector<std::string>> data_;
    void Check(size_type i, const std::string &msg) const;
};

#endif