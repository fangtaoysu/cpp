cmake_minimum_required(VERSION 3.0)
project(object_oriented)

set(CMAKE_CXX-STANDARD 11)
set(CMAKE_STANDARD_REQUIRED ON)

include_directories(head_dir)

file ( GLOB MAIN
    "main.cpp"
    "lib_mat.cpp"
    "book.cpp"
    "num_sequence.cpp"
    "fibonacci.cpp"
    "pell.cpp"
    "lucas.cpp"
    "pentagonal.cpp"
    "square.cpp"
    "triangular.cpp"
)

add_executable(main ${MAIN})