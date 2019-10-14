//
// Created by Ryan on 10/13/19.
//

#ifndef LAB2_RECURSIVEBFS_H
#define LAB2_RECURSIVEBFS_H


#include "SearchAlgorithm.h"
#include <queue>
#include <vector>
#include <iostream>
#include "Graph.h"

class RecursiveBFS : public SearchAlgorithm {
private:
    Graph g;

    vector<int> shortestPath(vector<vector<int>> paths);

    void printShortestPath(vector<vector<int>> paths);

    void BFSRecur(int source, int target);

    void BFSRecurUtil(int target, queue<vector<int>> &q, vector<bool> &visited, vector<vector<int>> &paths,
                      vector<int> &path);

public:
    void SearchData(int source, int target, Graph g);
};


#endif //LAB2_RECURSIVEBFS_H
