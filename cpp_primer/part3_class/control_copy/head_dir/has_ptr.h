#ifndef HAS_PTR_H
#define HAS_PTR_H
// 行为类似指针的类
#include <string>

class HasPtr {
public:
    friend void swap(HasPtr&, HasPtr&);
    HasPtr(const std::string &s = std::string()) 
        : ps_(new std::string(s)), i_(0), count_(new std::size_t(1)) {
    }
    HasPtr(const HasPtr &p)
        : ps_(p.ps_), i_(p.i_), count_(p.count_) {
        ++(*count_);
    }
    // 当添加了移动构造函数后，拷贝赋值运算符同时充当移动赋值运算符
    HasPtr& operator=(HasPtr);
    // HasPtr& operator=(const HasPtr&);
    HasPtr(HasPtr &&p) noexcept : ps_(p.ps_), i_(p.i_) {
        p.ps_ = 0;
    }
    std::string& GetPs() {
        return *ps_;
    }
    ~HasPtr();

private:
    std::string* ps_;
    int i_;
    std::size_t* count_; // 手动指针计数，确保内存正确释放
};

inline void swap(HasPtr& lhs, HasPtr& rhs) {
    using std::swap;
    swap(lhs.ps_, rhs.ps_);
    swap(lhs.i_, rhs.i_);
    swap(lhs.count_, rhs.count_);
}

#endif