//
// Created by Ryan on 10/15/19.
//

#ifndef LAB2_ASTAR_H
#define LAB2_ASTAR_H

#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include "SearchAlgorithm.h"

using namespace std;

class Astar : public SearchAlgorithm {
public:
    void AstarPath(vector<vector<pair<int, double> > > &graph, vector<tuple<int, int, int>> &positions, int &start,
                   int target);

    double findDistance(tuple<int, int, int> a, tuple<int, int, int> b);

    void SearchDataList(int source, int target, Graph g);

    void SearchDataMatrix(int source, int target, Graph g);
};


#endif //LAB2_ASTAR_H
