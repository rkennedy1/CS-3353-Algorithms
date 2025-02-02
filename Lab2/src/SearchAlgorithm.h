//
// Created by Ryan on 10/13/19.
//

#ifndef LAB2_SEARCHALGORITHM_H
#define LAB2_SEARCHALGORITHM_H

#include <vector>
#include "Graph.h"
#include <chrono>

using namespace std;

class SearchAlgorithm {
public:
    vector<int> finalPath;
    double finalDistance;
    double finalCost;
    int numNodesExplored;
    chrono::steady_clock::time_point startTime;
    chrono::steady_clock::time_point endTime;

    virtual void SearchDataList(int source, int target, Graph g) = 0;

    virtual void SearchDataMatrix(int source, int target, Graph g) = 0;
};

#endif //LAB2_SEARCHALGORITHM_H
