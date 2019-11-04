//
// Created by Ryan on 11/4/19.
//

#ifndef LAB3_GRAPH_H
#define LAB3_GRAPH_H

#include <vector>
#include <tuple>
#include <math.h>

using namespace std;

class Graph {
private:
    vector<tuple<int,float,float,float>> positions;
    int size;
public:
    Graph();
    void addNode(int, float,float,float);
    float getDist(int,int);
    float getPathDistance(vector<int>);
    vector<int> nodes;
};


#endif //LAB3_GRAPH_H
