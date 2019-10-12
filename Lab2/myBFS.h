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
    Graph g;
public:
    myBFS(Graph g);

    void BFS(int source, int target);

    void printPath(vector<int> parent, int i);

};


#endif //LAB2_MYBFS_H
