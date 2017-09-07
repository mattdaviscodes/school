cmake_minimum_required(VERSION 3.8)
project(c_test)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c)
add_executable(c_test ${SOURCE_FILES})