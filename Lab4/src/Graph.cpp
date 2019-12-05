//
// Created by Ryan on 11/4/19.
//

#include "Graph.h"

Graph::Graph() {}

void Graph::addNode(int node, float x, float y, float z) {
    nodes.push_back(node);
    positions.push_back(make_tuple(node, x, y, z));
    size++;
}

float Graph::getDist(int a, int b) {
    if (a == b)
        return 0;
    float x1 = get<1>(positions[a-1]);
    float x2 = get<1>(positions[b-1]);
    float y1 = get<2>(positions[a-1]);
    float y2 = get<2>(positions[b-1]);
    float z1 = get<3>(positions[a-1]);
    float z2 = get<3>(positions[b-1]);
    float dist = ((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1))+((z2-z1)*(z2-z1));
    dist = sqrt(dist);
    return dist;
}

float Graph::getPathDistance(vector<int> &path) {
    float distance=0.0;
    for (int i = 0; i < path.size()-1; i++) {
        if (path[i] != path[i + 1]) {
            distance += getDist(path[i], path[i + 1]);
        }
    }
    return distance;
}

void Graph::createMatrix() {
    matrix.resize(nodes.size());
    for (int i = 0; i < nodes.size(); i++) {
        matrix[i].resize(nodes.size());
        for (int j = 0; j < nodes.size(); j++) {
            matrix[i][j] = getDistMatrix(i, j);
        }
    }
}

float Graph::getDistMatrix(int a, int b) {
    if (a == b)
        return 0;
    float x1 = get<1>(positions[a]);
    float x2 = get<1>(positions[b]);
    float y1 = get<2>(positions[a]);
    float y2 = get<2>(positions[b]);
    float z1 = get<3>(positions[a]);
    float z2 = get<3>(positions[b]);
    float dist = ((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)) + ((z2 - z1) * (z2 - z1));
    dist = sqrt(dist);
    return dist;
}