//
// Created by Ryan on 11/2/19.
//

#include "DynamicProgramming.h"

void DynamicProgramming::shortestPath(Graph &g) {
    vector<int> path;
    for (int i = 1; i < g.nodes.size(); i++) {
        path.push_back(g.nodes[i]);
    }
    bestPath.erase(bestPath.begin(), bestPath.end());
    bestPath.push_back(g.nodes[0]);
    costOfBestPath = shortestPathRecur(1, 1, path, g);
    bestPath.push_back(g.nodes[0]);
    printPath();
}

float DynamicProgramming::shortestPathRecur(int start, int end, vector<int> path, Graph &g) {
    if (path.empty()) {
        nodesExplored++;
        return g.getDist(start, end);
    }
    vector<float> dists;
    float minDist = MAXFLOAT;
    for (int i = 0; i < path.size(); i++) {
        vector<int> tempPath = path;
        tempPath.erase(tempPath.begin() + i);
        minDist = MAXFLOAT;
        int minIndex = 0;
        for (int j = 2; j < g.nodes.size(); j++) {
            if (g.getDist(start, j) < minDist && start != j) {
                minDist = g.getDist(start, j);
                minIndex = j;
            }
        }
        nodesExplored++;
        if (bestPathNotContains(minIndex))
            bestPath.push_back(minIndex);
        dists.push_back(g.getDist(start, path[i]) + shortestPathRecur(path[i], end, tempPath, g));
    }
    minDist = MAXFLOAT;
    for (int i = 0; i < dists.size(); i++) {
        if (dists[i] < minDist)
            minDist = dists[i];
    }
    return minDist;
}

bool DynamicProgramming::bestPathNotContains(int a) {
    for (int i = 0; i < bestPath.size(); i++) {
        if (bestPath[i] == a)
            return false;
    }
    return true;
}

void DynamicProgramming::printPath() {
    cout << "Path: ";
    for (int i = 0; i < bestPath.size(); i++) {
        if (i < bestPath.size() - 1)
            cout << bestPath[i] << "->";
        else
            cout << bestPath[i] << endl << "Path Size:" << costOfBestPath << endl;
    }
    cout << "Nodes explored: " << nodesExplored << endl << endl;
}