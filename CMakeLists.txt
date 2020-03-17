cmake_minimum_required(VERSION 3.5.1)
project(openmp_test_clion)

# added -fopenmp
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fopenmp")

set(SOURCE_FILES main.cpp brick.cpp brick.hpp radix.cpp bitonic.cpp merge.cpp quick.cpp)
add_executable(openmp_test_clion ${SOURCE_FILES})