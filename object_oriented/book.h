#ifndef BOOK_H
#define BOOK_H


#include "lib_mat.h"
#include <string>
#include <iostream>

class Book : public LibMat {
public:
    Book(const string &title, const string &author)
        : title_(title), author_(author) {
        cout << "Book::Book( " << title_ << ", " << author_ << ")\n";
    }

    virtual ~Book() {
        cout << "Book::~Book() destructor\n";
    }
    // 虚拟调用实现多态
    virtual void Print() const {
        cout << "Book::Print() -- I am a Book object\n"
             << "title is " << title_
             << "\nauthor is " << author_ << endl;
    }

    const string& title() const {
        return title_;
    }

    const string& author() const {
        return author_;
    }

    
protected:
    string title_;
    string author_;
};

#endif