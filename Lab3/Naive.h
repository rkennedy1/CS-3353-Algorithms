//
// Created by Ryan on 11/2/19.
//

#ifndef LAB3_NAIVE_H
#define LAB3_NAIVE_H

#include <vector>
#include "Graph.h"
#include "TSP.h"

using namespace std;

class Naive : public TSP {
private:
    void checkBestPath(vector<int> path, Graph &g);
public:
    void shortestPath(Graph &g);
};


#endif //LAB3_NAIVE_H
