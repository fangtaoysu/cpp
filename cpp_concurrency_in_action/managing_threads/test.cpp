#include <iostream>


int main() {
    for (int i = 0; i < 30; ++i) {
        std::cout << (double)rand(0, 1) / RAND_MAX << std::endl;
    }

    return 0;
}