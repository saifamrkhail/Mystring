cmake_minimum_required(VERSION 3.23)
project(string)

set(CMAKE_CXX_STANDARD 14)

include(CheckCCompilerFlag)
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

add_executable(string main.cpp Mystring.cpp Mystring.h)
target_link_libraries(string gtest)