#include "./str_blob_ptr.h"
#include "./str_blob.h"
#include <stdexcept>

StrBlobPtr::StrBlobPtr(StrBlob &a, std::size_t sz)
        : wptr_(a.data_), curr_(sz) {
}

std::string& StrBlobPtr::DeRef() const {
    auto p = Check(curr_, "dereference past end");
    return (*p)[curr_];
}

StrBlobPtr& StrBlobPtr::Incr() {
    Check(curr_, "increment past end of StrBlobPtr");
    ++curr_;
    return *this;
}

StrBlobPtr& StrBlobPtr::operator++() {
    Incr();
    return *this;
}

StrBlobPtr StrBlobPtr::operator++(int) {
    auto ret = *this;
    Incr();
    return ret;
}

bool StrBlobPtr::operator!=(const StrBlobPtr& p) const {
    return curr_ != p.curr_;
}

std::string& StrBlobPtr::operator*() const {
    return DeRef();
}

std::shared_ptr<std::vector<std::string>> StrBlobPtr::Check(std::size_t i, const std::string& msg) const {
    auto ret = wptr_.lock(); // 如果管理对象存在，允许临时安全访问对象
    if (!ret) {
        throw std::runtime_error("unbound StrBlobPtr");
    }
    if (i >= ret->size()) {
        throw std::out_of_range(msg);
    }
    return ret;
}