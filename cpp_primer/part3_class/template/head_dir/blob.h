#ifndef BLOB_H
#define BLOB_H

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <initializer_list>
#include <stdexcept>


template <typename> class BlobPtr; // 将BlobPtr声明为模版，用于友元声明
// template <typename> class Blob; // 将Blob声明为模版，operator 参数声明
// template <typename T> // 将operator==声明为模版，用于友元声明
// bool operator==(const Blob<T>&, const Blob<T>&);

// Template class definition
template <typename T>
class Blob {
public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;

    friend class BlobPtr<T>;
    // friend bool operator==(const Blob<T>&, const Blob<T>&);
    // Constructors
    Blob();
    Blob(std::initializer_list<T> il);
    template <typename It>
    Blob(It beg, It end);

    // Member functions
    size_type size() const {
        return data_->size();
    }
    bool empty() const;
    void push_back(const T &t);
    void push_back(T &&t);
    void pop_back();
    void Print() const;
    T& front() const;
    T& back() const;
    T& operator[](size_type i);

private:
    // Data member
    std::shared_ptr<std::vector<T>> data_;

    // Utility function to check index validity
    void Check(size_type i, const std::string &msg) const;
};


// 模版函数必须定义在头文件中
// Template member function definitions

// Default constructor
template <typename T>
Blob<T>::Blob() : data_(std::make_shared<std::vector<T>>()) {
}

// Constructor from initializer list
template <typename T>
Blob<T>::Blob(std::initializer_list<T> il)
    : data_(std::make_shared<std::vector<T>>(il)) {
}

// Check function to validate index
template <typename T>
void Blob<T>::Check(size_type i, const std::string &msg) const {
    if (i >= data_->size()) {
        throw std::out_of_range(msg);
    }
}

// pop_back function implementation
template <typename T>
void Blob<T>::pop_back() {
    Check(0, "PopBack on empty Blob");
    data_->pop_back();
}

// Print function to display the contents of the Blob
template <typename T>
void Blob<T>::Print() const {
    for (const auto &val : *data_) {
        std::cout << val << "\t";
    }
    std::cout << std::endl;
}

// Check if Blob is empty
template <typename T>
bool Blob<T>::empty() const {
    return data_->empty();
}

// Push back an element by const reference
template <typename T>
void Blob<T>::push_back(const T &t) {
    data_->push_back(t);
}

// Push back an element by rvalue reference
template <typename T>
void Blob<T>::push_back(T &&t) {
    data_->push_back(std::move(t));
}

// Return the first element
template <typename T>
T& Blob<T>::front() const {
    Check(0, "Front on empty Blob");
    return data_->front();
}

// Return the last element
template <typename T>
T& Blob<T>::back() const {
    Check(0, "Back on empty Blob");
    return data_->back();
}

// Access element by index
template <typename T>
T& Blob<T>::operator[](size_type i) {
    Check(i, "i out of index range");
    return (*data_)[i];
}

template <typename T> // 类的类型参数
template <typename It> // 构造函数的类型参数
Blob<T>::Blob(It beg, It end) : data_(std::make_shared<std::vector<T>>(beg, end)) {
}


#endif // BLOB_H
