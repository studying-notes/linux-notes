cmake_minimum_required(VERSION 3.21)
project(CH0203 C)

set(CMAKE_C_STANDARD 11)

include_directories(add)
include_directories(sub)

add_executable(CH0203
        add/add.h
        add/add_float.c
        add/add_int.c
        sub/sub.h
        sub/sub_float.c
        sub/sub_int.c
        main.c)
