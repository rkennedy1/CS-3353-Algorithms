cmake_minimum_required(VERSION 3.15)
project(Lab4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Lab4
        Algo.h
        Graph.cpp
        Graph.h
        main.cpp
        TSP.h
        TSPAlgo.cpp
        TSPAlgo.h Tabu.cpp Tabu.h GeneticAlgo.cpp GeneticAlgo.h dp.h)
