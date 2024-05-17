#ifndef BOOK_H
#define BOOK_H


#include "lib_mat.h"
#include <string>
#include <iostream>

class Book : public LibMat {
public:
    Book(const std::string &title, const std::string &author)
        : title_(title), author_(author) {
        std::cout << "Book::Book( " << title_ << ", " << author_ << ")\n";
    }

    virtual ~Book() {
        std::cout << "Book::~Book() destructor\n";
    }
    // 虚拟调用实现多态
    virtual void Print() const {
        std::cout << "Book::Print() -- I am a Book object\n"
             << "title is " << title_
             << "\nauthor is " << author_ << std::endl;
    }

    const std::string& title() const {
        return title_;
    }

    const std::string& author() const {
        return author_;
    }

    
protected:
    std::string title_;
    std::string author_;
};

#endif