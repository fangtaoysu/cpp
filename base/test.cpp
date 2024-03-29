#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;
const int a = 1, b = 1;
int main() {
    
    string c, d;
    static int e, f;
    cout << &(a) << endl;
    cout << &(b) << endl;
    cout << &(c) << endl;
    cout << &(d) << endl;
    cout << &("dfas") << endl;
    cout << &(e) << endl;

    return 0;
}