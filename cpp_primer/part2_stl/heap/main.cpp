#include <iostream>
#include <string>
#include <vector>

#include "str_blob.h"
#include "str_blob_ptr.h"


void Test() {
    StrBlob sb1({"1", "2", "abc"});
    StrBlobPtr sbp1(sb1);
    std::cout << *sbp1++ << std::endl;
    // --sbp1;
    std::cout << *sbp1-- << std::endl;
    std::cout << *sbp1 << std::endl;
    std::cout << *(++sbp1) << std::endl;
    std::cout << *(--sbp1) << std::endl;
    std::cout << sbp1->size() << std::endl; // "1"的长度
    std::cout << *(++sbp1) << std::endl;
}

int main() {
    Test();
    return 0;
}