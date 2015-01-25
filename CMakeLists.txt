cmake_minimum_required(VERSION 2.8.4)
project(ipi_ws2014)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(Z02 Z02/main.cpp)
add_executable(Z04 Z02/main.cpp)
add_executable(Z08 Z08/FehlerWert.cpp Z08/IntList.cpp Z08/main.cpp)
add_executable(Z12 Z12/main.cpp)