#include <iostream>
#include "lib_mat.h"
#include "book.h"
#include "audio_book.h"
#include "num_sequence.h"
#include "fibonacci.h"



using namespace std;

void Print(const LibMat &mat) {
    cout << "in global print(): about to print mat.print()\n";
    mat.Print();
}

void TestClass() {
    cout << "\n" << "Creating a AudioBook object to print()\n";
    AudioBook audio_book("hello", "world", "ft");
    Print(audio_book);
}

void TestInherit() {
   Fibonacci fib;
   cout << "fib: beginning at element 1 for 1 element:" << fib << endl;

   Fibonacci fib2(16);
   cout << "fib2: beginning at element 1 for 16 element:" << fib2 << endl;

   Fibonacci fib3(8, 12);
   cout << "fib3: beginning at element 8 for 12 element:" << fib3 << endl;

}

int main() {
    // TestClass();

    TestInherit();
    return 0;
}