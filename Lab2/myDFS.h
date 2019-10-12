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

using namespace std;

class myDFS {
private:
    Graph g;
public:
    myDFS(Graph g);

    void DFSRecur(int s, int t);

    void DFSRecurUtil(int s, int t, vector<bool> visited, int *path, int path_index);

    void DFS(int source, vector<bool> visited);

    void DFSUtil(int source);

    void printPath(vector<int> parent, int i);
};


#endif //LAB2_MYDFS_H
