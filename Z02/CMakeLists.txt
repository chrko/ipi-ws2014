cmake_minimum_required(VERSION 2.8.4)
project(Z02)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Z02 ${SOURCE_FILES})