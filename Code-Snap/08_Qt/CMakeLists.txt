cmake_minimum_required(VERSION 3.14)
project(08_Qt)

find_package(Qt5 COMPONENTS Core REQUIRED)


set(CMAKE_CXX_STANDARD 14)

add_executable(08_Qt main.cpp)

target_link_libraries(08_Qt Qt5::Core)