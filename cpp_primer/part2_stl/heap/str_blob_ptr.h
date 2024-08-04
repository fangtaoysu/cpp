#ifndef STR_BLOB_PTR_H
#define STR_BLOB_PTR_H
#include <memory>
#include <string>
#include <vector>

/**
 * weak_ptr 并不会贡献共享对象的引用数，因此不会影响所指对象的生命周期
 */

class StrBlob; // 使用StrBlob类之前需要声明

class StrBlobPtr {
public:
    StrBlobPtr() : curr_(0) {
    }
    StrBlobPtr(StrBlob &a, std::size_t sz=0);
    // 运算符
    std::string& operator*() const;
    StrBlobPtr& operator++(); // ++i
    StrBlobPtr operator++(int); // i++
    bool operator!=(const StrBlobPtr& p) const;
private:
    std::string& DeRef() const;
    StrBlobPtr& Incr(); // 前缀递增
    std::shared_ptr<std::vector<std::string>> Check(std::size_t, const std::string&) const;
    std::weak_ptr<std::vector<std::string>> wptr_;
    std::size_t curr_;
};

#endif