#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include "tool.h"
#include <iterator>


using namespace std;
vector<int> filter(const vector<int> &, int, bool (*pred)(int, int));
template <typename InputIterator, typename OutputIterator, typename ElemType, typename Comp>
OutputIterator filter(InputIterator, InputIterator, OutputIterator, const ElemType&, Comp);
int count_occurs(const vector<int> &, int);

bool less_than(int val1, int val2) {
    return val1 < val2;
}
bool greater_than(int val1, int val2) {
    return val1 > val2;
}

int main() {
    int SIZE = 10;
    int arr[SIZE] = {
        1, 2, 3, 43, 4, 5, 3234, 16, 34, 5
    };
    vector<int> ivec(arr, arr+SIZE);
    vector<int> output(SIZE);
    int arr2[SIZE];
    display(ivec.begin(), ivec.end());
    // vector<int>::iterator last = filter(ivec.begin(), ivec.end(), output.begin(), 17, greater<int>());
    vector<int> output2;
    // insertion adapter
    filter(ivec.begin(), ivec.end(), back_inserter(output2), 1, greater<int>());
    // int* end = filter(arr, arr+SIZE, arr2, 17, greater<int>());
    display(output2.begin(), output2.end());

    return 0;
}

int count_occurs(const vector<int> &vec, int val) {
    vector<int>::const_iterator it = vec.begin();
    int occurs_count = 0;
    // 使用迭代器顺序查找元素个数
    while ((it = find(it, vec.end(), val)) != vec.end()) {
        ++occurs_count;
        ++it;
    }
    return occurs_count;
}

template <typename InputIterator, typename OutputIterator, typename ElemType, typename Comp>
OutputIterator filter(InputIterator first, InputIterator last, OutputIterator at, const ElemType& value, Comp pred) {
    /**
     * 版本二：参考count_occurs的写法，引入迭代器和模版；引入function object
     * vector<int> output2;
     * filter(ivec.begin(), ivec.end(), back_inserter(output2), 1, greater<int>());
    */
    while ((first = find_if(first, last, bind2nd(pred, value))) != last) {
        // cout << *first << "\t";
        *at++ = *first++;
    }
    // cout << endl;
    return at;
}

vector<int> filter(const vector<int> &vec, int val, bool (*pred)(int, int)) {
    /**
     * 版本1：用户可自定义需要筛选的函数
     * bool less_than(int val1, int val2);
     * vector<int> nvec = filter(ivec, 17, greater_than);
    */
    vector<int> nvec;
    for (int ix = 0; ix < vec.size(); ++ix) {
        if (pred(vec[ix], val)) {
            nvec.push_back(vec[ix]);
        }
    }
    return nvec;
}