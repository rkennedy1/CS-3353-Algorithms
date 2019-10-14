//
// Created by Ryan on 10/13/19.
//

#ifndef LAB2_RECURSIVEDFS_H
#define LAB2_RECURSIVEDFS_H

#include <vector>
#include "SearchAlgorithm.h"
#include <iostream>
#include "Graph.h"

using namespace std;

class RecursiveDFS : public SearchAlgorithm {
private:
    Graph g;

    void DFSRecur(int source, int target);

    void DFSRecurUtil(int s, int t, vector<bool> visited, vector<int> path, vector<vector<int>> &paths);

    vector<int> shortestPath(vector<vector<int>> paths);

    void printShortestPath(vector<vector<int>> paths);

public:
    void SearchData(int source, int target, Graph g);
};

#endif //LAB2_RECURSIVEDFS_H
