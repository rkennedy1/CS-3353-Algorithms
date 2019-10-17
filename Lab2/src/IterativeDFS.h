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

    void DFSIterList(int source, int target);

    void DFSIterMatrix(int source, int target);

    double calculateDistance(vector<int> path);

public:
    void SearchDataList(int source, int target, Graph g);

    void SearchDataMatrix(int source, int target, Graph g);

};


#endif //LAB2_ITERATIVEDFS_H
