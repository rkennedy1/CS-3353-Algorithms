//
// Created by Ryan on 11/26/19.
//

#ifndef LAB4_TABU_H
#define LAB4_TABU_H

#include "Graph.h"
#include "Solution.h"
#include "TSP.h"
#include <vector>
#include <tuple>
#include <random>
#include <stdlib.h>

using namespace std;

class Tabu : public TSP {
public:
    void shortestPath(Graph &);

private:
    vector<pair<float, vector<int>>> tabu;
    int size = 20;
    int iter = 800;

    bool contains(pair<float, vector<int>>);

    pair<float, vector<int>> randomPair(Graph &g);

    void swapAllNeighbors(pair<float, vector<int>> &, Graph &);

    void swapRandomNeighbors(pair<float, vector<int>> &, Graph &);

    void swap(int, int, Graph &, pair<float, vector<int>> &);
};


#endif //LAB4_TABU_H
