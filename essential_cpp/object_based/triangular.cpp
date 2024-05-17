#include "triangular.h"
#include <algorithm>
#include "../tool/tool.h"

vector<int> Triangular::kElems_;
int Triangular::kMaxElems_ = 5050;

Triangular::Triangular() {
    length_ = 1;
    beg_pos_ = 1;
    next_ = 0;
}

Triangular::Triangular(int len)
    : length_ (len > 0 ? len : 1) {
    beg_pos_ = 1;
    next_ = 0;
    int elem_cnt = beg_pos_ + length_ - 1;
    if (kElems_.size() < elem_cnt) {
        GenElements(elem_cnt);
    }
}

Triangular::Triangular(int len, int beg_pos)
    : length_(len > 0 ? len : 1), beg_pos_(beg_pos > 0 ? beg_pos : 1) {
    next_ = beg_pos_ - 1;
    int elem_cnt = beg_pos_ + length_ - 1;
    if (kElems_.size() < elem_cnt) {
        GenElements(elem_cnt);
    }
}

// 通过成员初始化列表实现构造函数 实现类对象的复制操作
// 构造函数内部需要实现具体的复制操作
Triangular::Triangular(const Triangular &rhs)
    : length_(rhs.length_), beg_pos_(rhs.beg_pos_), next_(rhs.beg_pos_ - 1){}

bool Triangular::Next(int &val) {
    if (next_ < beg_pos_ + length_ - 1) {
        val = kElems_[next_++];
        return true;
    }
    return false;
}

Triangular& Triangular::Copy(const Triangular& rhs) {
    if (this != &rhs) {
        length_ = rhs.length_;
        beg_pos_ = rhs.beg_pos_;
        next_ = rhs.next_;
    }

    return *this;
}

bool Triangular::IsElem(int val) {
    if (!kElems_.size() || kElems_[kElems_.size() - 1] < val ) {
        GenElemsToValue(val);
    }

    vector<int>::iterator found_it;
    vector<int>::iterator end_it = kElems_.end();

    found_it = find(kElems_.begin(), end_it, val);
    return  found_it != end_it;
} 

void Triangular::GenElemsToValue(int val) {
    int ix = kElems_.size();
    if (!ix) {
        kElems_.push_back(1);
        ix = 1;
    }
    while (kElems_[ix-1] < val && ix < kMaxElems_) {
        // cout << "elems to value: " << ix*(ix+1)/2 << endl;
        ++ix;
        kElems_.push_back(ix*(ix+1)/2);
    }

    if (ix == kMaxElems_) {
        cerr << "Triangular Sequence: Oops~ value too large " << val 
             << "-- exceeds max size of " << kMaxElems_ << endl;
    }
}

void Triangular::GenElements(int length) {
    if (length < 0 || length > kMaxElems_) {
        cerr << "Triangular Sequence: Oops~ length is wrong " << length << endl;
        return;
    }
    if (kElems_.size() < length) {
        int ix = kElems_.size() ? kElems_.size()+1 : 1;
        for (; ix <= length; ++ix) {
            kElems_.push_back(ix*(ix+1)/2);
        }
    }
}

void Triangular::Display(int length, int beg_pos, ostream &os) {
    if (length < 0 || length > kMaxElems_) {
        cerr << "Triangular Display: Oops~ length is wrong " << length << endl;
        return;
    }
    if (beg_pos < 0 || beg_pos > kMaxElems_) {
        cerr << "Triangular Display: Oops~ beg_pos is wrong " << beg_pos << endl;
        return;
    }
    for (int ix = beg_pos; ix < beg_pos + length; ++ix) {
        os << kElems_[ix-1] << " ";
    }
    os << endl;
}

ostream& operator<<(ostream &os, const Triangular &rhs) {
    os << "( " << rhs.Length()
       << ", " << rhs.BegPos() << " )";

    rhs.Display(rhs.Length(), rhs.BegPos(), os);
    return os; 
}

istream& operator>>(istream& is, Triangular& rhs) {
    char ch1, ch2;
    is >> ch1 >> rhs.length_  >> ch2 >> rhs.beg_pos_;
    rhs.NextReset();

    return is;
}