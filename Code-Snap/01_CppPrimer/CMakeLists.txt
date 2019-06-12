cmake_minimum_required(VERSION 3.14)
project(01_CppPrimer)

set(CMAKE_CXX_STANDARD 14)

add_executable(01_CppPrimer
        main.cpp String.cpp String.h ThreadManager.cpp ThreadManager.h)
