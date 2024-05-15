#include <iostream>
#include "head_dir/lib_mat.h"
#include "head_dir/book.h"
#include "head_dir/audio_book.h"
#include "head_dir/num_sequence.h"
#include "head_dir/fibonacci.h"
// #include "head_dir/pell.h"
// #include "head_dir/lucas.h"
// #include "head_dir/pentagonal.h"
// #include "head_dir/square.h"
// #include "head_dir/triangular.h"


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
    Fibonacci<8> fib1;
    std::cout << fib1 << std::endl;
    Fibonacci<8, 8> fib2;
    std::cout << fib2 << std::endl;
    Fibonacci<12, 8> fib3;
    std::cout << fib3 << std::endl;
    
    // Lucas lucas1;
    // std::cout << lucas1 << std::endl;
    // Lucas lucas2(10);
    // std::cout << lucas2 << std::endl;
    // Lucas lucas3(8, 12);
    // std::cout << lucas3 << std::endl;
    
    // Pell pell1;
    // std::cout << pell1 << std::endl;
    // Pell pell2(10);
    // std::cout << pell2 << std::endl;
    // Pell pell3(8, 12);
    // std::cout << pell3 << std::endl;
    
    // Pentagonal penta1;
    // std::cout << penta1 << std::endl;
    // Pentagonal penta2(10);
    // std::cout << penta2 << std::endl;
    // Pentagonal penta3(8, 12);
    // std::cout << penta3 << std::endl;
    
    // Square square1;
    // std::cout << square1 << std::endl;
    // Square square2(10);
    // std::cout << square2 << std::endl;
    // Square square3(8, 12);
    // std::cout << square3 << std::endl;
    
    // Triangular tria1;
    // std::cout << tria1 << std::endl;
    // Triangular tria2(10);
    // std::cout << tria2 << std::endl;
    // Triangular tria3(8, 12);
    // std::cout << tria3 << std::endl;

}

int main() {
    // TestClass();

    TestInherit();
    return 0;
}