cmake_minimum_required(VERSION 3.0)
project(object_oriented)

set(CMAKE_CXX-STANDARD 11)
set(CMAKE_STANDARD_REQUIRED ON)

include_directories(head_dir)

file ( GLOB MAIN
    "main.cpp"
    "lib_mat.cpp"
    "book.cpp"
    "audio_book.cpp"
    "triangular.cpp"
    "square.cpp"
    "pentagonal.cpp"
    "pell.cpp"
    "num_sequence.cpp"
    "lucas.cpp"
    "fibonacci.cpp"
)

add_executable(main ${MAIN})