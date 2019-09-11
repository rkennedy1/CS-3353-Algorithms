cmake_minimum_required(VERSION 3.12)
project(src)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(src
        Algorithm.h
        Bubble.cpp
        Bubble.h
        generator.cpp
        generator.h
        Insertion.cpp
        Insertion.h
        main.cpp
        Merge.cpp
        Merge.h
        Sort.cpp
        Sort.h
        SortAlgorithm.h)
