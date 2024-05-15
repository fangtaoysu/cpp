#include "head_dir/fibonacci.h"


template <int length, int beg_pos>
std::vector<int> Fibonacci<length, beg_pos>::kElems_;

// Fibonacci::Fibonacci(const Fibonacci &rhs)
//     : NumSequence(rhs) { // 使用虚基类的默认构造函数
// }


template <int length, int beg_pos>
void Fibonacci<length, beg_pos>::GenElems(int pos) const {
    if (kElems_.empty()) {
        kElems_.push_back(1);
        kElems_.push_back(1);
    }
    if (kElems_.size() <= pos) {
        int n = kElems_.size();
        int n1 = kElems_[n-1];
        int n2 = kElems_[n-1];
        for (; n <= pos; ++n) {
            int elem = n1 + n2;
            // std::cout << "GenElems: " << elem << std::endl;
            kElems_.push_back(elem);
            n2 = n1;
            n1 = elem;
        }
    }
}

