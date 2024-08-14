#include "./head_dir/sales_data.h"


SalesData& SalesData::operator=(const SalesData& rhs) {
    if (this == &rhs) {
        return *this;
    }
    book_no_ = rhs.book_no_;
    units_sold_ = rhs.units_sold_;
    revenue_ = rhs.revenue_;
    return *this; 
}