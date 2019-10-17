cmake_minimum_required(VERSION 3.12)
project(Lab2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab2 main.cpp Algorithm.h Search.cpp Search.h Graph.cpp Graph.h Dijkstra.cpp Dijkstra.h SearchAlgorithm.h IterativeDFS.cpp IterativeDFS.h RecursiveDFS.cpp RecursiveDFS.h IterativeBFS.cpp IterativeBFS.h RecursiveBFS.cpp RecursiveBFS.h Astar.cpp Astar.h)