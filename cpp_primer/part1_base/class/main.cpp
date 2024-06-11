#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <initializer_list>
#include <cstdarg>
#include <cstdlib>
#include <cassert>
#include "head_folders/sales_data.h"
#include "head_folders/screen.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::begin;
using std::end;
using std::cerr;


void TestSale() {
    SalesData total;
    if (Read(cin, total)) {
        SalesData trans;
        while (Read(cin, trans)) {
            if (total.Isbn() == trans.Isbn()) {
                total.Combine(trans);
            } else {
                Print(cout, total) << endl;
                total.Combine(trans);
            }
        }
        Print(cout, total) << endl;
    } else {
        cerr << "no data???" << endl;
    }
}

void TestScreen() {
    Screen my_screen;
    my_screen.Move(4, 0).Set('#');
    cout << my_screen.Get(4, 0) << endl;
}

int main() {
    // TestSale();
    TestScreen();
    return 0;
}