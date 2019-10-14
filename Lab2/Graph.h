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
    vector<vector<pair<int, int>>> adjMatrix;
    list<int> *adjList;

    void loadGraphs(vector<vector<pair<int, int>>> &inputMatrix);

    void addEdge(int index, int value);
};


#endif //LAB2_GRAPH_H
