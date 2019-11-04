//
// Created by Ryan on 11/2/19.
//

#ifndef LAB3_NAIVE_H
#define LAB3_NAIVE_H

#include <vector>
#include <tuple>
#include <iostream>
#include "Graph.h"

using namespace std;

class Naive {
private:
    int nodeExplored;
    vector<int> bestPath;
    float costOfBestPath;
    void printPath();
public:
    void shortestPath(Graph &g);
    void checkBestPath(vector<int>path, Graph & g);
};


#endif //LAB3_NAIVE_H
