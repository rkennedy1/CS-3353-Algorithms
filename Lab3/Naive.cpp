//
// Created by Ryan on 11/2/19.
//

#include "Naive.h"


void Naive::shortestPath(Graph &g) {
    vector<int> nodes;
    for (int i = 0; i < g.nodes.size(); i++) {
        nodes.push_back(g.nodes[i]);
    }
    permutationsDone = 0;
    pathDist = INT_MAX;
    finalPath = nodes;
    do {
        permutationsDone++;
        if (nodes[0] == g.nodes[0]) {
            checkBestPath(nodes, g);
        }
    } while(next_permutation(nodes.begin(), nodes.end()));
}

void Naive::checkBestPath(vector<int> path, Graph &g) {
    vector<int> tempPath = path;
    tempPath.push_back(path[0]);
    float distance = g.getPathDistance(tempPath);
    if (distance < pathDist) {
        pathDist = distance;
        finalPath = tempPath;
    }
}