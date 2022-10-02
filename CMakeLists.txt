cmake_minimum_required(VERSION 3.23)
project(string)

set(CMAKE_CXX_STANDARD 14)

add_executable(string main.cpp Mystring.cpp include/Mystring.h)
target_link_libraries(string gtest)