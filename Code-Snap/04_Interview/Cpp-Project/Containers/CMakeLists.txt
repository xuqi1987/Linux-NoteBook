cmake_minimum_required(VERSION 3.13)
project(Containers)

set(CMAKE_CXX_STANDARD 14)

add_executable(Containers main.cpp SequenceContainer.cpp SequenceContainer.h Type.h AssociativeContainers.cpp AssociativeContainers.h)