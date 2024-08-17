#ifndef SALES_DARA_H
#define SALES_DATA_H
#include <string>
#include <iostream>

using std::string;
using std::istream;
using std::ostream;

class SalesData {
// class默认成员是private
// struct默认成员是public
friend istream &Read(istream &is, SalesData &item);
friend ostream &Print(ostream &os, const SalesData &item);
friend SalesData Add(const SalesData &lhs, const SalesData &rhs);
friend std::ostream& operator<<(std::ostream& os, const SalesData& item);
friend std::istream& operator>>(std::istream& is, SalesData& item);
friend SalesData operator+(const SalesData& lhs, const SalesData& rhs);
friend bool operator==(const SalesData& lhs, const SalesData& rhs);
friend bool operator!=(const SalesData& lhs, const SalesData& rhs);

private:
    double revenue_ = 0.0; // 总收入
    string book_no_; // 书编码
    unsigned units_sold_ = 0; // 总数
    double AvgPrice() const;

public:
    // SalesData() = default;
    // SalesData(const string &s = "") : book_no_(s) { }
    // SalesData(istream &is);
    // 非委托构造函数
    SalesData(const string &s, unsigned n, double p)
        : book_no_(s), units_sold_(n), revenue_(p*n) { }
    // 委托构造函数
    SalesData() : SalesData("", 0, 0) {}
    SalesData(const string &s) : SalesData (s, 0, 0) {}
    SalesData(istream &is) : SalesData() {
        Read(is, *this);
    }
    SalesData& operator+=(const SalesData& rhs);

    string Isbn() const {
        return book_no_;
    };
    SalesData &Combine(const SalesData &rhs);
};

// 友元的声明仅指定访问权限，最好单独再声明一次
istream &Read(istream &is, SalesData &item);
ostream &Print(ostream &os, const SalesData &item);
SalesData Add(const SalesData &lhs, const SalesData &rhs);
// os在每次输出都会变化，因此不能设为const
// 考虑到调用问题，输入输出重载运算符不能设为类成员
std::ostream& operator<<(std::ostream& os, const SalesData& item);
std::istream& operator>>(std::istream& is, SalesData& item);
SalesData operator+(const SalesData& lhs, const SalesData& rhs);
bool operator==(const SalesData& lhs, const SalesData& rhs);
bool operator!=(const SalesData& lhs, const SalesData& rhs);
#endif