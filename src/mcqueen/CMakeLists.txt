cmake_minimum_required(VERSION 3.12)
project(mcqueen)

set(CMAKE_CXX_STANDARD 14)

add_library(mcqueen SHARED src/library.cpp)