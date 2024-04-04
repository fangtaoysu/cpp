#include <iostream>
#include <vector>
#include <typeinfo>
#include <list>


using namespace std;
template <typename elemType>
elemType* find(const elemType*, int, const elemType&);
template <typename elemType>
elemType* find(const elemType*, const elemType*, const elemType&);
template <typename elemType>
inline const elemType* my_begin(const vector<elemType> &vec);
template <typename elemType>
inline const elemType* my_end(const vector<elemType> &vec);
template <typename IteratorType, typename elemType>
IteratorType find(IteratorType, IteratorType, const elemType&);

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


template <typename IteratorType, typename elemType>
IteratorType find(const IteratorType first, const IteratorType last, const elemType& value) {
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

template <typename elemType>
inline const elemType* my_begin(const vector<elemType> &vec) {
    return vec.empty() ? 0 : &vec[0];
}
template <typename elemType>
inline const elemType* my_end(const vector<elemType> &vec) {
    return vec.empty() ? 0 : &vec[vec.size()];
}

template <typename elemType>
elemType* find(const elemType* first, const elemType* last, const elemType &value) {
    /**
     * 版本2：兼容数组和vector
     * 思路：直接操作指针
     * template <typename elemType>
     * inline const elemType* my_begin(const vector<elemType> &vec);
     * template <typename elemType>
     * inline const elemType* my_end(const vector<elemType> &vec);
     * int* result1 = find(iarray, iarray+SIZE, value);
     * int* result2 = find(my_begin(ivec), my_end(ivec), value);
    */
    if (!first || !last) {
        return nullptr;
    }
    while (first != last) {
        if (*first == value) {
            return (elemType*)(first);
        }
        ++first;
    }
    return nullptr;
}

template <typename elemType>
elemType* find(const elemType* array, int size, const elemType& value) {
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
            return (elemType*)(array);
        }
    }
    return nullptr;
}
