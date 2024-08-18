#ifndef STR_VEC_H
#define STR_VEC_H
#include <string>

class StrVec {
private:
    /* data */
public:
    StrVec(/* args */)
        : elements_(nullptr), first_free_(nullptr), cap_(nullptr) {
    }
    // 拷贝构造函数
    StrVec(const StrVec&);
    // 移动构造函数
    StrVec(StrVec &&s) noexcept;
    // 拷贝赋值运算符 
    // noexcept关键字 - 不抛出异常
    // 移动赋值运算符
    StrVec& operator=(const StrVec&);
    StrVec operator=(StrVec&&) noexcept;
    // 花括号列表赋值
    StrVec& operator=(std::initializer_list<std::string>);
    std::string& operator[](std::size_t n);
    const std::string& operator[](std::size_t n) const;
    ~StrVec();

    void push_back(const std::string&);
    void push_back(std::string&&);
    size_t size() const {
        return first_free_ - elements_;
    }
    size_t capacity() const {
        return cap_ - elements_;
    }
    std::string* begin() const {
        return elements_;
    }
    std::string* end() const {
        return first_free_;
    }

private:
    // 分配元素
    static std::allocator<std::string> alloc_;
    void CheckNAlloc();
    std::pair<std::string*, std::string*> AllocNCopy (const std::string*, const std::string*);
    void free();
    void reallocate();
    // 指向数组首元素指针
    std::string* elements_;
    // 指向数组第一个空闲元素指针
    std::string* first_free_;
    // 指向数组尾后位置的指针
    std::string* cap_;
};


#endif