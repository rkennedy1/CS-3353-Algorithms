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
#include <chrono>


using namespace std;

class Tabu : public TSP {
public:
    void shortestPath(Graph &);

private:
    vector<pair<float, vector<int>>> list;
    int size = 10;
    int iterNum = 1000;

    bool contains(pair<float, vector<int>>);

    pair<float, vector<int>> init(Graph &);

    pair<float, vector<int>> findNeighbor(pair<float, vector<int>>, Graph &);

    void swap(int, int, Graph &, pair<float, vector<int>> &);
};


#endif //LAB4_TABU_H
