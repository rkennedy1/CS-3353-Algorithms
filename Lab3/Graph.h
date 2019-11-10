//
// Created by Ryan on 11/4/19.
//

#ifndef LAB3_GRAPH_H
#define LAB3_GRAPH_H

#include <vector>
#include <tuple>
#include <math.h>
#include <iostream>

using namespace std;

class Graph {
public:
    Graph();

    vector<tuple<int, float, float, float>> positions;
    int size;
    vector<int> nodes;
    vector<vector<float>> matrix;

    void addNode(int, float,float,float);

    void createMatrix();
    float getDist(int,int);

    float getDistMatrix(int, int);

    float getPathDistance(vector<int> &path);

};


#endif //LAB3_GRAPH_H
