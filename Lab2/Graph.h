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
    vector<tuple<int, int, int>> positions;
    vector<vector<pair<int, double>>> adjMatrix;

    void loadGraphs(vector<vector<pair<int, double>>> &inputList, vector<tuple<int, int, int>> &positions);

    void addMatrixEdge(int a, int b, double weight);

    void addListEdge(int index, int value);
};


#endif //LAB2_GRAPH_H
