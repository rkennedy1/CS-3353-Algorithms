cmake_minimum_required(VERSION 3.15)
project(Lab3)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab3 main.cpp Naive.cpp Naive.h DynamicProgramming.cpp DynamicProgramming.h Algo.h TSPAlgo.cpp TSPAlgo.h Graph.cpp Graph.h TSP.h)