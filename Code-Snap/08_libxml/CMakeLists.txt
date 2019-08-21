cmake_minimum_required(VERSION 3.13)
project(08_libxml)

set(CMAKE_CXX_STANDARD 11)
INCLUDE_DIRECTORIES(/usr/include/libxml2)
set(LINK_LIB_LIST xml2 Qt5Gui Qt5Core)

add_executable(08_libxml main.cpp)
target_link_libraries(08_libxml ${LINK_LIB_LIST})