#include "./head_dir/str_vec.h"
#include <utility>
#include <memory>

// 静态成员需要在类外部进行定义
std::allocator<std::string> StrVec::alloc_;
void StrVec::push_back(const std::string& s) {
    CheckNAlloc();
    alloc_.construct(first_free_++, s);
}

std::pair<std::string*, std::string*> StrVec::AllocNCopy(const std::string* b, const std::string* e) {
    // 返回新空间的开始位置和尾后位置
    auto data = alloc_.allocate(e - b);
    return {
        data, std::uninitialized_copy(b, e, data)
    };
}

void StrVec::free() {
    if (elements_) {
        // 逆序销毁
        for (auto p = first_free_; p != elements_; ) {
            alloc_.destroy(--p);
        }
        alloc_.deallocate(elements_, cap_ - elements_);
    }
}

StrVec::StrVec(const StrVec &s) {
    auto new_data = AllocNCopy(s.begin(), s.end());
    elements_ = new_data.first;
    first_free_ = new_data.second;
    cap_ = new_data.second;
}

StrVec::~StrVec() {
    free();
}

StrVec& StrVec::operator=(const StrVec& rhs) {
    auto data = AllocNCopy(rhs.begin(), rhs.end());
    free();
    elements_ = data.first;
    first_free_ = data.second;
    cap_ = data.second;
    return *this;
}

void StrVec::reallocate() {
    auto new_capacity = size() ? 2 * size() : 1;
    auto new_data = alloc_.allocate(new_capacity);
    auto dest = new_data; // 指向新数组中的下一个空闲位置
    auto elem = elements_; // 指向旧数组中下一个元素
    for (size_t i = 0; i != size(); ++i) {
        alloc_.construct(dest++, std::move(*elem++));
    }
    free();
    elements_ = new_data;
    first_free_ = dest;
    cap_ = elements_ + new_capacity;
}

void StrVec::CheckNAlloc() {
    if (size() == capacity()) {
        reallocate();
    }
}