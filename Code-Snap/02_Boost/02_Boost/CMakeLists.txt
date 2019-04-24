cmake_minimum_required(VERSION 3.13)
project(02)

set(CMAKE_CXX_STANDARD 14)

set(BOOST_ROOT /home/xuqi/proj/Private/boost_1_70_0)

find_package(Boost COMPONENTS regex system thread REQUIRED)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})

    MESSAGE( STATUS "Boost_INCLUDE_DIRS = ${Boost_INCLUDE_DIRS}.")
    MESSAGE( STATUS "Boost_LIBRARIES = ${Boost_LIBRARIES}.")
    MESSAGE( STATUS "Boost_LIB_VERSION = ${Boost_LIB_VERSION}.")

    add_executable(02 main.cpp)
    target_link_libraries (02 ${Boost_LIBRARIES})
endif()

IF(DEBUG_mode)
    add_definitions(-DDEBUG)
    SET(CMAKE_BUILE_TYPE DEBUG)
ENDIF()

