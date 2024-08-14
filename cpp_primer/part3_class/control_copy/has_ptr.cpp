#include "./head_dir/has_ptr.h"


HasPtr::~HasPtr() {
    if (--(*count_) == 0) {
        delete ps_;
        delete count_;
    }
}

// HasPtr& HasPtr::operator=(const HasPtr &rhs) {
//     if (&rhs == this) {
//         return *this;
//     }
//     ++(*rhs.count_);
//     // 如果指针计数值为0，说明该指针是最后一个指向该地址的指针
//     // 此时如果不通过该指针释放该地址，而直接修改指针指向的地址，意味着这块地址无法使用代码释放，将造成内存泄漏的风险
//     if (--(*count_) == 0) {
//         delete ps_;
//         delete count_;
//     }
//     ps_ = rhs.ps_;
//     i_ = rhs.i_;
//     count_ = rhs.count_;
//     return *this;
// }

HasPtr& HasPtr::operator=(HasPtr rhs) {
    swap(*this, rhs);
    return *this;
}