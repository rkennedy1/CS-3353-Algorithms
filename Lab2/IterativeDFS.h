//
// Created by Ryan on 10/13/19.
//

#ifndef LAB2_ITERATIVEDFS_H
#define LAB2_ITERATIVEDFS_H

#include <stack>
#include "Graph.h"
#include "SearchAlgorithm.h"
#include <iostream>

class IterativeDFS : public SearchAlgorithm {
private:
    Graph g;

    void DFSIter(int source, int target);

    void printShortestPath(vector<vector<int>> paths);

    vector<int> shortestPath(vector<vector<int>> paths);

    int isNotVisited(int x, vector<int> &path);

public:
    void SearchData(int source, int target, Graph g);
};


#endif //LAB2_ITERATIVEDFS_H
