cmake_minimum_required(VERSION 3.0)
project(tempaltes)

# 设置cpp标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加头文件目录
include_directories(head_dir)

file (GLOB MAIN
    "main.cpp"
    "binary_tree.cpp"
    "binary_tree_node.cpp"
    )

add_executable(main ${MAIN})