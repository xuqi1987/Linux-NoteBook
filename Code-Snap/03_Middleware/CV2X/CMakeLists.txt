project(CV2X)
cmake_minimum_required(VERSION 3.1.3)
#使能c++11
set(CMAKE_CXX_STANDARD 11)

#设置库文件路径
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

#设置可执行程序路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

#设置工程源码根目录
set(ToolKit_Root ${CMAKE_SOURCE_DIR}/3rdpart/LinuxToolKit/src)

set(CV2X_Root ${CMAKE_SOURCE_DIR}/src/)
set(CV2XAsn1_Root ${CMAKE_SOURCE_DIR}/3rdpart/CV2XAsn1/src)

#设置头文件目录
INCLUDE_DIRECTORIES(${ToolKit_Root})
INCLUDE_DIRECTORIES(${CV2X_Root})
INCLUDE_DIRECTORIES(${CV2XAsn1_Root})

#收集源代码
file(GLOB ToolKit_src_list ${ToolKit_Root}/*/*.cpp ${ToolKit_Root}/*/*.h ${ToolKit_Root}/*/*.c)
file(GLOB CV2X_src_list ${CV2X_Root}/*.cpp ${CV2X_Root}/*/*.cpp  ${CV2X_Root}/*/*.h ${CV2X_Root}/*/*.c ${CV2X_Root}/*/*/*.cpp  ${CV2X_Root}/*/*/*.h ${CV2X_Root}/*/*/*.c)

file(GLOB CV2XAsn1_src_list ${CV2XAsn1_Root}/*.cpp  ${CV2XAsn1_Root}/*.h ${CV2XAsn1_Root}/*.c)


message(STATUS "File:${CV2XAsn1_Root}")

#添加库
add_library(toolkit STATIC ${ToolKit_src_list})
add_library(asn1 STATIC ${CV2XAsn1_src_list})

set(LINK_LIB_LIST  toolkit asn1)

list(APPEND LINK_LIB_LIST pthread)
#打印库文件
message(STATUS "将链接依赖库:${LINK_LIB_LIST}")

add_executable(${CMAKE_PROJECT_NAME} ${CV2X_src_list})

#链接库
TARGET_LINK_LIBRARIES(${CMAKE_PROJECT_NAME} ${LINK_LIB_LIST})

#测试程序
add_subdirectory(tests)



























