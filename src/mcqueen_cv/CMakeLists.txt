CMAKE_MINIMUM_REQUIRED(VERSION 3.10.2)

project(mcqueen-cv)
set(CMAKE_CXX_STANDARD 14)
find_library(mcn_lib mcqueen)
find_path(mcn_path mcqueen)

#======================================================================
# Recurse to subdirectories

add_subdirectory(src)
add_subdirectory(examples)
