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
private:
    void DijkstraAlgo(vector<vector<pair<int, double> > > &graph, int &start, int target);
public:
    void SearchDataList(int source, int target, Graph g);

    void SearchDataMatrix(int source, int target, Graph g);
};


#endif //LAB2_DIJKSTRA_H
