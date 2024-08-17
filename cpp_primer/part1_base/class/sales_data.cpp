#include "head_folders/sales_data.h"

double SalesData::AvgPrice() const {
    if (units_sold_) {
        return revenue_ / units_sold_;
    } else {
        return 0;
    }
}

SalesData& SalesData::Combine(const SalesData &rhs) {
    units_sold_ += rhs.units_sold_;
    revenue_ += rhs.revenue_;
    return *this; // 其他成员使用调用对象的成员
}

// SalesData::SalesData(istream &is) {
//     Read(is, *this);
// }

istream &Read(istream &is, SalesData &item) {
    double price = 0;
    is >> item.book_no_ >> item.units_sold_ >> price;
    item.revenue_ = price * item.units_sold_;
    return is;
}

ostream &Print(ostream &os, const SalesData &item) {
    os << item.Isbn() << " " 
       << item.units_sold_ << " "
       << item.revenue_ << " "
       << item.AvgPrice();
    return os; 
}

SalesData Add(const SalesData &lhs, const SalesData &rhs) {
    SalesData sum = lhs;
    sum.Combine(rhs);
    return sum;
}

std::ostream& operator<<(std::ostream& os, const SalesData& item) {
    os << item.Isbn() << " "
       << item.units_sold_ << " "
       << item.revenue_ << " "
       << item.AvgPrice();
    return os;
}

std::istream& operator>>(std::istream& is, SalesData& item) {
    double price; // 先读入price，再使用
    is >> item.book_no_ >> item.units_sold_ >> price;
    if (is) { // 需要考虑可能读取失败
        item.revenue_ = price * item.units_sold_;
    } else {
        SalesData();
    }
    return is;
}

SalesData operator+(const SalesData& lhs, const SalesData& rhs) {
    SalesData sum = lhs;
    sum += rhs; // 使用SalesData的+=重载运算符
    return sum;
}

SalesData& SalesData::operator+=(const SalesData& rhs) {
    revenue_ += rhs.revenue_;
    units_sold_ += rhs.units_sold_;
    return *this;
}

bool operator==(const SalesData& lhs, const SalesData& rhs) {
    return lhs.Isbn() == rhs.Isbn() &&
           lhs.units_sold_ == rhs.units_sold_ &&
           lhs.revenue_ == rhs.revenue_;
}

bool operator!=(const SalesData& lhs, const SalesData& rhs) {
    return !(lhs == rhs);
}

