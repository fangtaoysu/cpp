#include <iostream>
#include <vector>
#include <typeinfo>
#include <list>


using namespace std;
template <typename ElemType>
ElemType* find(const ElemType*, int, const ElemType&);
template <typename ElemType>
ElemType* find(const ElemType*, const ElemType*, const ElemType&);
template <typename ElemType>
inline const ElemType* my_begin(const vector<ElemType> &vec);
template <typename ElemType>
inline const ElemType* my_end(const vector<ElemType> &vec);
template <typename IteratorType, typename ElemType>
IteratorType find(IteratorType, IteratorType, const ElemType&);

int main() {
    int SIZE = 5;
    int iarray[SIZE] = {1, 2, 3, 4, 5};
    vector<int> ivec(iarray, iarray + SIZE);
    list<int> ilst(iarray, iarray + SIZE);

    int* result1 = find(iarray, iarray+SIZE, 2);
    vector<int>::iterator result2 = find(ivec.begin(), ivec.end(), 7);
    list<int>::iterator result3 = find(ilst.begin(), ilst.end(), 3);
    
    
    if (result1 != iarray+SIZE) {   
        cout << "find it" << endl;
    } else {
        cout << "Value not found" << endl;
    }
    if (result2 != ivec.end()) {   
        cout << "find it" << endl;
    } else {
        cout << "Value not found" << endl;
    }
    if (result3 != ilst.end()) {   
        cout << "find it" << endl;
    } else {
        cout << "Value not found" << endl;
    }
    
    return 0;
}


template <typename IteratorType, typename ElemType>
IteratorType find(const IteratorType first, const IteratorType last, const ElemType& value) {
    /**
     * 版本3：兼容数组，array和链表（链表的节点通过指针连接，之前的访问方式行不通，只能通过迭代器去兼容）
     * 思路：使用迭代器
     * 注意：迭代器不能声明为const类型，否则不能++
     * int* result1 = find(iarray, iarray+SIZE, 2);
     * vector<int>::iterator result2 = find(ivec.begin(), ivec.end(), 7);
     * list<int>::iterator result3 = find(ilst.begin(), ilst.end(), 3);
    */
    while (first != last) {
        if (*first == value) {
            return first;
        }
        ++first;
    }
    return last;
}

template <typename ElemType>
inline const ElemType* my_begin(const vector<ElemType> &vec) {
    return vec.empty() ? 0 : &vec[0];
}
template <typename ElemType>
inline const ElemType* my_end(const vector<ElemType> &vec) {
    return vec.empty() ? 0 : &vec[vec.size()];
}

template <typename ElemType>
ElemType* find(const ElemType* first, const ElemType* last, const ElemType &value) {
    /**
     * 版本2：兼容数组和vector
     * 思路：直接操作指针
     * template <typename ElemType>
     * inline const ElemType* my_begin(const vector<ElemType> &vec);
     * template <typename ElemType>
     * inline const ElemType* my_end(const vector<ElemType> &vec);
     * int* result1 = find(iarray, iarray+SIZE, value);
     * int* result2 = find(my_begin(ivec), my_end(ivec), value);
    */
    if (!first || !last) {
        return nullptr;
    }
    while (first != last) {
        if (*first == value) {
            return (ElemType*)(first);
        }
        ++first;
    }
    return nullptr;
}

template <typename ElemType>
ElemType* find(const ElemType* array, int size, const ElemType& value) {
    /**
     * 版本1：兼容数组和vector
     * 思路：由于数组和vector获取大小的方式不一样，因此传入size
     * int* result1 = find(iarray, SIZE, value);
     * int* result2 = find(ivec.data(), SIZE, value);
    */
    if (!array || size < 1) {
        return nullptr;
    }
    for (int ix = 0; ix < size; ++ix, ++array) {
        if (*array == value) {
            return (ElemType*)(array);
        }
    }
    return nullptr;
}
