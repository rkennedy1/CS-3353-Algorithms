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

    void printPath(vector<int> path);
public:
    myBFS(vector<vector<int>> g);

    void BFSIter(int source, int target);

    void BFSRecur(int source, int);
};


#endif //LAB2_MYBFS_H
