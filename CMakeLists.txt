cmake_minimum_required(VERSION 3.15)
project(my_code_of_algorithm_course_in_hhu C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(my_code_of_algorithm_course_in_hhu
        algo.c
        alg.cpp)
