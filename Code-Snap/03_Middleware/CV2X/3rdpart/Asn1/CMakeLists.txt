cmake_minimum_required(VERSION 3.13)
project(Asn1 C)

set(CMAKE_C_STANDARD 11)

#设置库文件路径
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

#设置可执行程序路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

#设置工程源码根目录
set(ASN1_Root ${CMAKE_SOURCE_DIR}/src)

#设置头文件目录
INCLUDE_DIRECTORIES(${ASN1_Root})

#收集源代码
file(GLOB ASN1_src_list ${ASN1_Root}/*.cpp ${ASN1_Root}/*.h ${ASN1_Root}/*.c)

message(STATUS "File:${ASN1_src_list}")
#添加库
add_library(asn1 STATIC ${ASN1_src_list})

set(LINK_LIB_LIST  asn1)

list(APPEND LINK_LIB_LIST)
#打印库文件
message(STATUS "将链接依赖库:${LINK_LIB_LIST}")


#编译动态库

add_library(${CMAKE_PROJECT_NAME}_shared SHARED ${ASN1_src_list})
target_link_libraries(${CMAKE_PROJECT_NAME}_shared ${LINK_LIB_LIST})
set_target_properties(${CMAKE_PROJECT_NAME}_shared PROPERTIES OUTPUT_NAME "${CMAKE_PROJECT_NAME}")



#链接库
#TARGET_LINK_LIBRARIES(${CMAKE_PROJECT_NAME} ${LINK_LIB_LIST})

#add_executable(${CMAKE_PROJECT_NAME} ${ASN1_src_list})

#测试程序
add_subdirectory(tests)



























