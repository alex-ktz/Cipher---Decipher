cmake_minimum_required(VERSION 4.1)
project(ex1 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(ex1
        cipher.c
        cipher.h
        main.c
        tests.c
        tests.h)
