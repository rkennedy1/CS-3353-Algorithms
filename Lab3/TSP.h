//
// Created by Ryan on 11/9/19.
//

#ifndef LAB3_TSP_H
#define LAB3_TSP_H

#include "Graph.h"

using namespace std;

class TSP {
public:
    vector<int> finalPath;
    float pathDist;
    int permutationsDone;

    virtual void shortestPath(Graph &g) = 0;
};

#endif //LAB3_TSP_H


