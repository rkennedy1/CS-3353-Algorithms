//
// Created by Ryan on 11/2/19.
//

#ifndef LAB3_DYNAMICPROGRAMMING_H
#define LAB3_DYNAMICPROGRAMMING_H

#include "Graph.h"
#include <iostream>

using namespace std;

class DynamicProgramming {
private:
    int nodesExplored;
    vector<int> bestPath;
    float costOfBestPath;

    bool bestPathNotContains(int a);

    void printPath();

    float shortestPathRecur(int start, int end, vector<int> path, Graph &g);

public:
    void shortestPath(Graph &g);
};


#endif //LAB3_DYNAMICPROGRAMMING_H
