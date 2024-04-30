#include <iostream>
#include "lib_mat.h"
#include "book.h"
#include "audio_book.h"
#include "num_sequence.h"
#include "fibonacci.h"


void Print(const LibMat &mat) {
    std::cout << "in global print(): about to print mat.print()\n";
    mat.Print();
}

void TestClass() {
    std::cout << "\n" << "Creating a AudioBook object to print()\n";
    AudioBook audio_book("hello", "world", "ft");
    Print(audio_book);
}

void TestInherit() {
   Fibonacci fib;
   std::cout << "fib: beginning at element 1 for 1 element:" << fib << std::endl;

   Fibonacci fib2(45);
   std::cout << "fib2: beginning at element 1 for 45 element:" << fib2 << std::endl;

   Fibonacci fib3(8, 12);
   std::cout << "fib3: beginning at element 8 for 12 element:" << fib3 << std::endl;

    const int pos = 8;

    Fibonacci fib4;
    Display(std::cout, fib4, pos);
}

int main() {
    // TestClass();

    TestInherit();
    return 0;
}