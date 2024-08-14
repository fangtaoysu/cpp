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
    StrVec(const StrVec&);
    StrVec& operator=(const StrVec&);
    ~StrVec();

    void push_back(const std::string&);
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