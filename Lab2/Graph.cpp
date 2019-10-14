//
// Created by Ryan on 10/2/19.
//

#include "Graph.h"

Graph::Graph() {

}

void Graph::loadGraphs(vector<vector<pair<int, int>>> &inputMatrix) {
    adjMatrix = inputMatrix;
    list<int> *tempList;
    int temp = inputMatrix.size();
    adjList = new list<int>[temp];
    for (int i = 0; i < inputMatrix.size(); i++) {
        for (int j = 0; j < inputMatrix[i].size(); j++) {
            //addEdge(i, inputMatrix[i][j]);
        }
    }
}

void Graph::addEdge(int index, int value) {
    adjList[index].push_back(value);
}

Graph::Graph(Graph *pGraph) {
    this->adjList = pGraph->adjList;
    this->adjMatrix = pGraph->adjMatrix;
    this->numVertexes = pGraph->numVertexes;
}
