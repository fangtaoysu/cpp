#ifndef BLOB_PTR_H
#define BLOB_PTR_H
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "./blob.h"


template <typename T>
class BlobPtr {
public:
    BlobPtr() :curr_(0) {
    }
    BlobPtr(Blob<T> &a, std::size_t sz = 0) : w_ptr_(a.data_), curr_(sz) {
    }
    T& operator*() const {
        auto p = Check(curr_, "dereference past end");
        return (*p)[curr_];
    }
    BlobPtr& operator++();
    BlobPtr operator++(int);
    BlobPtr& operator--();
    BlobPtr operator--(int);
private:
    std::shared_ptr<std::vector<T>> Check(std::size_t, const std::string&) const;
    std::weak_ptr<std::vector<T>> w_ptr_;
    std::size_t curr_;
};

template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int) {
    BlobPtr res = *this;
    ++*this; // 调用前置版本，因此前置版本负责检查
    return res;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++() {
    ++curr_;
    Check(curr_, "increment past end of BlobPtr");
    return *this;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator--(int) {
    BlobPtr res = *this;
    --*this;
    return res;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator--() {
    --curr_;
    Check(curr_, "decrement past begin of BlobPtr");
    return *this;
}

template <typename T>
std::shared_ptr<std::vector<T>> BlobPtr<T>::Check(std::size_t i, const std::string& msg) const {
    auto ret = w_ptr_.lock(); // 如果管理对象存在，允许临时安全访问对象
    if (!ret) {
        throw std::runtime_error("unbound BlobPtr");
    }
    if (i >= ret->size()) {
        throw std::out_of_range(msg);
    }
    return ret;
}


#endif