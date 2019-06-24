cmake_minimum_required(VERSION 3.13)
project(01_CppPrimer)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(01_CppPrimer
        main.cpp
        ThreadDemo.cpp ThreadDemo.h)
TARGET_LINK_LIBRARIES( 01_CppPrimer
        pthread
        )