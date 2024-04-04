#include <iostream>
#include "../tool/tool.h"


using namespace std;

int main() {
    int SIZE = 5;
    int arr[SIZE] = {1, 4, 5, 23, 5};
    vector<int> ivec(arr, arr+SIZE);

    display(ivec.begin(), ivec.end());

    return 0;
}