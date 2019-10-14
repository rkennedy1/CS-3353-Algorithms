//
// Created by Ryan on 10/1/19.
//

#ifndef LAB2_MYBFS_H
#define LAB2_MYBFS_H

#include <queue>
#include <iostream>
#import <list>
#include <vector>
#include "Graph.h"

using namespace std;

class myBFS {
private:
    vector<vector<int>> g;

    vector<int> shortestPath(vector<vector<int>> paths);

    int isNotVisited(int x, vector<int> &path);

    void printShortestPath(vector<vector<int>> paths);
public:
    myBFS(vector<vector<int>> g);
    void BFSIter(int source, int target);

    void BFSRecur(int source, int target);

    void BFSRecurUtil(int target, queue<int> &q, vector<bool> &visited, vector<vector<int>> &paths, vector<int> &path);
};


#endif //LAB2_MYBFS_H
