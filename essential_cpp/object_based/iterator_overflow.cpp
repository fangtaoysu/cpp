#include "iterator_overflow.h"
#include <string>
#include <sstrean>

const char* IteratorOverflow::what() const {
    // 用于将不同格式转为字符串
    std::ostringstream ex_msg;
    static std::string msg;
    // 将"Internal error: current index "等信息输出到变量ex_msg中
    ex_msg << "Internal error: current index " << index_
           << " exceeds maximum bound: " << max_;

    // 转为string对象
    msg = ex_msg.str();
    // string对象转为const char*
    return msg.c_str()
}