//
// Created by Ryan on 10/2/19.
//

#include "Graph.h"

Graph::Graph() {

}

Graph::Graph(int V) {
    this->V = V;
    this->adj = new std::list<int>[V];
}

void Graph::addEdge(int v, int value) {
    this->adj[v].push_back(value);
}