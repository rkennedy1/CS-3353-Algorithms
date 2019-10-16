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

    double calculateDistance(vector<int> path);

    void BFSRecurList(int source, int target);

    void BFSRecurUtilList(int target, queue<vector<int>> &q, vector<bool> &visited, vector<vector<int>> &paths,
                          vector<int> &path);

    void BFSRecurMatrix(int source, int target);

    void BFSRecurUtilMatrix(int target, queue<vector<int>> &q, vector<bool> &visited, vector<vector<int>> &paths,
                      vector<int> &path);

public:
    void SearchDataList(int source, int target, Graph g);

    void SearchDataMatrix(int source, int target, Graph g);
};


#endif //LAB2_RECURSIVEBFS_H
