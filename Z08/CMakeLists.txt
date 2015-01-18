cmake_minimum_required(VERSION 2.8.4)
project(Z08)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp IntList.cpp FehlerWert.cpp)
add_executable(Z08 ${SOURCE_FILES})