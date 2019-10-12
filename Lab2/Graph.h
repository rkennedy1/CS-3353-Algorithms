//
// Created by Ryan on 10/2/19.
//

#ifndef LAB2_GRAPH_H
#define LAB2_GRAPH_H

#include <list>

class Graph {
public:
    Graph();

    int V;
    std::list<int> *adj;

    Graph(int V);

    void addEdge(int v, int w);
};


#endif //LAB2_GRAPH_H
