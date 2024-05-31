#ifndef SALES_DARA_H
#define SALES_DATA_H
#include <string>
#include <iostream>

using std::string;
using std::istream;
using std::ostream;

class SalesData {
// 默认成员是private
friend istream &Read(istream &is, SalesData &item);
friend ostream &Print(ostream &os, const SalesData &item);
friend SalesData Add(const SalesData &lhs, const SalesData &rhs);

private:
    double revenue_ = 0.0; // 总收入
    string book_no_; // 书编码
    unsigned units_sold_ = 0; // 总数
    double AvgPrice() const;

public:
    SalesData() = default;
    SalesData(const string &s) : book_no_(s) { }
    SalesData(const string &s, unsigned n, double p)
        : book_no_(s), units_sold_(n), revenue_(p*n) { }
    SalesData(istream &is);

    string Isbn() const {
        return book_no_;
    };
    SalesData &Combine(const SalesData &rhs);
};

// 友元的声明仅指定访问权限，最好单独再声明一次
istream &Read(istream &is, SalesData &item);
ostream &Print(ostream &os, const SalesData &item);
SalesData Add(const SalesData &lhs, const SalesData &rhs);


#endif