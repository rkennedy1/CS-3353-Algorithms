//
// Created by Ryan on 10/2/19.
//

#ifndef LAB2_MYDFS_H
#define LAB2_MYDFS_H

#include <stack>
#include <iostream>
#import <list>
#include <vector>
#include "Graph.h"
#include "SearchAlgorithm.h"

using namespace std;

class myDFS {
private:
    vector<vector<int>> graph;

    void DFSRecurUtil(int s, int t, vector<bool> visited, vector<int> path, vector<vector<int>> &paths);
    vector<int> shortestPath(vector<vector<int>> paths);
    int isNotVisited(int x, vector<int> &path);
    void printShortestPath(vector<vector<int>> paths);
public:
    myDFS(vector<vector<int>> g);
    void DFSRecur(int source, int target);
    void DFSIter(int source, int target);
};


#endif //LAB2_MYDFS_H
