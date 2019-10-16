//
// Created by Ryan on 10/12/19.
//

#ifndef LAB2_DIJKSTRA_H
#define LAB2_DIJKSTRA_H

#include "Graph.h"
#include <vector>
#include <iostream>
#include <queue>
#include "SearchAlgorithm.h"


using namespace std;

class Dijkstra : public SearchAlgorithm {
public:

    vector<int> DijkstraAlgo(vector<vector<pair<int, int> > > &graph, int &start, int target);

    void printShortestPath(vector<pair<vector<int>, int>>);

    void PrintShortestPath(vector<int> &dist, int &start);

    void SearchData(int source, int target, Graph g);

    vector<int> shortestPath(vector<pair<vector<int>, int>> paths);
};


#endif //LAB2_DIJKSTRA_H
