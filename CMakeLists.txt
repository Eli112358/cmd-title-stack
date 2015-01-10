cmake_minimum_required(VERSION 2.8.4)
project(cmd_title_stack)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/stack.cpp)
add_executable(cmd_title_stack ${SOURCE_FILES})
