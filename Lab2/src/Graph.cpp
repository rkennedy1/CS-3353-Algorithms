//
// Created by Ryan on 10/2/19.
//

#include "Graph.h"

Graph::Graph() {

}

void Graph::loadGraphs(vector<vector<pair<int, double>>> &inputList, vector<tuple<double, double, double>> &positions) {
    adjList = inputList;
    this->positions = positions;
    adjMatrix.resize(inputList.size());
    for (int i = 0; i < inputList.size(); i++) {
        adjMatrix[i].resize(inputList.size());
    }
    for (int i = 0; i < inputList.size(); i++) {
        for (int j = 0; j < inputList[i].size(); j++) {
            addMatrixEdge(i, inputList[i][j].first, inputList[i][j].second);
        }
    }
}

void Graph::addMatrixEdge(int a, int b, double weight) {
    this->adjMatrix[a][b].first = 1;
    this->adjMatrix[a][b].second = weight;

    this->adjMatrix[b][a].first = 1;
    this->adjMatrix[b][a].second = weight;

}

Graph::Graph(Graph *pGraph) {
    this->adjList = pGraph->adjList;
    this->adjList = pGraph->adjList;
    this->numVertexes = pGraph->numVertexes;
}
