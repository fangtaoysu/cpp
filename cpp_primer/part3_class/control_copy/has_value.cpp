#include "./head_dir/has_value.h"

HasValue& HasValue::operator=(const HasValue& rhs) {
    if (this == &rhs) {
        return *this;
    }
    auto ptr = new std::string(*rhs.ps_);
    delete ps_;
    ps_ = ptr;
    i_ = rhs.i_;
    return *this;
}