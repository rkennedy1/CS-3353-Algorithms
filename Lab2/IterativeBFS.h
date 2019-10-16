//
// Created by Ryan on 10/13/19.
//

#ifndef LAB2_ITERATIVEBFS_H
#define LAB2_ITERATIVEBFS_H


#include "SearchAlgorithm.h"
#include <queue>
#include <iostream>
#include <vector>
#include "Graph.h"


class IterativeBFS : public SearchAlgorithm {
private:
    Graph g;

    void BFSIterList(int source, int target);

    void BFSIterMatrix(int source, int target);

    double calculateDistance(vector<int> path);

public:
    void SearchDataList(int source, int target, Graph g);

    void SearchDataMatrix(int source, int target, Graph g);

};


#endif //LAB2_ITERATIVEBFS_H
