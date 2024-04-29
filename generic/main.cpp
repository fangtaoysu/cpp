/**
 * 实现 function object
*/
#include <iostream>
#include <ostream>
#include <vector>
#include <algorithm>
#include "less_than.h"


using namespace std;
int CountLessThan(const vector<int> &vec, int comp) {
    LessThan lt(comp);

    int count = 0;
    for (int ix = 0; ix < vec.size(); ++ix) {
        if (lt(vec[ix])) {
            ++count;
        }
    }
    return count;
}

void PrintLessThan(const vector<int> &vec, int comp) {
    LessThan lt(comp);
    vector<int>::const_iterator iter = vec.begin();
    vector<int>::const_iterator it_end = vec.end();

    cout << "elements less than " << lt.CompVal() << endl;
    while ((iter = find_if(iter, it_end, lt)) != it_end) {
        cout << *iter << " ";
        ++iter;
    }
    cout << "\n";
}

int main () {
    const int SIZE = 16;
    int ia[SIZE] = {
        1, 343, 545, 233, 45, 6, 45, 453, 22, 32, 45, 234, 223, 7, 4, 22
    };
    vector<int> vec(ia, ia+SIZE);
    int comp_val = 100;

    cout << "Number of elements less than " << comp_val
         << " are " << CountLessThan(vec, comp_val) << endl;

    PrintLessThan(vec, comp_val);
}