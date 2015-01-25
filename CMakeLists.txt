cmake_minimum_required(VERSION 2.8.4)
project(ipi_ws2014)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(Z02-exc Z02/main.cpp)
add_executable(Z04-exc Z04/main.cpp)
add_executable(Z08-exc Z08/FehlerWert.cpp Z08/IntList.cpp Z08/main.cpp)
add_executable(Z12-exc Z12/main.cpp)