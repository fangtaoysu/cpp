cmake_minimum_required(VERSION 3.0)
project(object-based)

# 设置cpp标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加头文件目录
include_directories(object-based)

file (GLOB MAIN
    "main.cpp"
    "triangular.cpp"
    "triangular_iterator.cpp"
    "stack.cpp"
    "../tool/tool.cpp"
    )

add_executable(main ${MAIN})
