#ifndef PRINT_STRING_H
#define PRINT_STRING_H
#include <string>
#include <iostream>


class PrintString {
public:
    PrintString(std::ostream &o=std::cout, char c=' ')
        : os_(o), sep_(c) {
    }
    void operator() (const std::string &s) const {
        os_ << s << sep_;
    }
private:
    std::ostream &os_;
    char sep_;
};


#endif