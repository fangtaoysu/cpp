#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>


class SalesData {
public:
    // 拷贝构造函数
    SalesData(const SalesData&)=default; // =default使用编译器合成的版本
    SalesData()=default;
    SalesData& operator=(const SalesData& rhs);
    ~SalesData()=default; // 合成的版本是内联的
private:
    std::string book_no_;
    int units_sold_ = 0;
    double revenue_ = 0.0;
};

#endif