cmake_minimum_required(VERSION 3.20)
project(Hw6Task3 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Hw6Task3
        list.c
        list.h
        main.c
        mergeSort.c
        mergeSort.h
        tests.c
        tests.h
        cmake-build-debug/data.txt)
