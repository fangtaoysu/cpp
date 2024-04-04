#ifndef TOOL_H
#define TOOL_H

#include <vector>
#include <string>
#include <iostream>

// 带模版的定义必须在头文件里实现
template <typename IteratorType>
void display(IteratorType first, IteratorType last) {
    while (first != last) {
        std::cout << *first++ << "\t";
    }
    std::cout << std::endl;
}


#endif