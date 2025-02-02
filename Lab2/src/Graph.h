//
// Created by Ryan on 10/2/19.
//

#ifndef LAB2_GRAPH_H
#define LAB2_GRAPH_H

#include <list>
#include <vector>

using namespace std;
class Graph {
public:
    Graph();

    Graph(Graph *pGraph);

    int numVertexes;
    vector<vector<pair<int, double>>> adjList;
    vector<tuple<double, double, double>> positions;
    vector<vector<pair<int, double>>> adjMatrix;

    void loadGraphs(vector<vector<pair<int, double>>> &inputList, vector<tuple<double, double, double>> &positions);

    void addMatrixEdge(int a, int b, double weight);

};


#endif //LAB2_GRAPH_H
