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

    void DFSRecurList(int source, int target, vector<bool> &visited, vector<int> path);

    void DFSRecurMatrix(int source, int target, vector<bool> &visited, vector<int> path);

    double calculateDistance(vector<int> path);

public:
    void SearchDataList(int source, int target, Graph g);

    void SearchDataMatrix(int source, int target, Graph g);
};

#endif //LAB2_RECURSIVEDFS_H
