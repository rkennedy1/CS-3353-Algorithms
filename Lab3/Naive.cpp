//
// Created by Ryan on 11/2/19.
//

#include "Naive.h"


void Naive::shortestPath(Graph &g) {
    vector<pair<int, vector<int>>> solutions;
    vector<int> nodes;
    for (int i = 0; i < g.nodes.size(); i++) {
        nodes.push_back(g.nodes[i]);
    }
    sort(nodes.begin(), nodes.end());
    nodesExplored = 0;
    costOfBestPath = INT_MAX;
    bestPath = nodes;
    do {
        if (nodes[0] == g.nodes[0]) {
            checkBestPath(nodes, g);
            nodesExplored++;
        }
    } while(next_permutation(nodes.begin(), nodes.end()));
    printPath();
}

void Naive::checkBestPath(vector<int> path, Graph &g) {
    vector<int> tempPath = path;
    tempPath.push_back(path[0]);
    float distance = g.getPathDistance(tempPath);
    if (distance < costOfBestPath) {
        costOfBestPath = distance;
        bestPath = tempPath;
    }
}

void Naive::printPath() {
    cout << "Path: ";
    for (int i = 0; i < bestPath.size(); i++) {
        if (i < bestPath.size()-1)
            cout << bestPath[i] << "->";
        else
            cout << bestPath[i] << endl << "Path Size:" << costOfBestPath << endl;
    }
    cout << "Nodes explored: " << nodesExplored << endl << endl;
}