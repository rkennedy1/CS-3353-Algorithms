//
// Created by Ryan on 11/2/19.
//

#include "Naive.h"


void Naive::shortestPath(Graph &g) {
    vector<pair<int, vector<int>>> solutions;
    vector<int> nodes = g.nodes;
    nodeExplored = 0;
    costOfBestPath = INT_MAX;
    do {
        checkBestPath(nodes, g);
        nodeExplored++;
    } while(next_permutation(nodes.begin(), nodes.end()));
    printPath();
    cout << "Nodes explored: " << nodeExplored << endl << endl;
}

void Naive::checkBestPath(vector<int>path, Graph & g){
    path.push_back(path[0]);
    float distance = g.getPathDistance(path);
    if (distance < costOfBestPath) {
        costOfBestPath = distance;
        bestPath = path;
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
}