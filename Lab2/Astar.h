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
    void
    AstarPath(vector<vector<pair<int, int> > > &graph, vector<tuple<int, int, int>> &positions, int &start, int target);

    int findDistance(tuple<int, int, int> a, tuple<int, int, int> b);

    void printShortestPath(vector<int> adjDistance, int start);

    void printShortestPath(vector<pair<vector<int>, int>> paths);

    void SearchData(int source, int target, Graph g);
};


#endif //LAB2_ASTAR_H
