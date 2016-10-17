cmake_minimum_required(VERSION 3.6)
project(double_linked_list)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp double_linked.cpp double_linked.h)
add_executable(double_linked_list ${SOURCE_FILES})