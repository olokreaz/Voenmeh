cmake_minimum_required(VERSION 3.27)
project(Voenmeh C)

set(CMAKE_C_STANDARD 23)


# static lib
add_library(lib STATIC lib.c lib.h)

add_executable(Voenmeh_Practic_3 main.c)