//
// Created by Ryan on 10/12/19.
//

#ifndef LAB2_DIJKSTRA_H
#define LAB2_DIJKSTRA_H

#include "Graph.h"
#include <vector>
#include <iostream>
#include <queue>


using namespace std;

class Dijkstra {
public:
    void dijkstra(vector<vector<pair<int, int>>> &graph, int dest, int start);

    vector<int> DijkstraSP(vector<vector<pair<int, int> > > &graph, int &start, int target);

    void printShortestPath(vector<pair<vector<int>, int>>);

    void PrintShortestPath(vector<int> &dist, int &start);
};


#endif //LAB2_DIJKSTRA_H
