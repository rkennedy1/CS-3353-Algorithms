//
// Created by Ryan on 10/13/19.
//

#include "RecursiveDFS.h"

void RecursiveDFS::DFSRecurList(int source, int target, vector<bool> &visited, vector<int> path) {
    visited[source] = true;
    path.push_back(source);
    this->numNodesExplored++;
    if (source == target) {
        this->finalPath = path;
        this->finalDistance = calculateDistance(path);
        this->finalCost = -1;
        return;
    } else {
        for (int i = 0; i < g.adjList[source].size(); i++) {
            if (!visited[g.adjList[source][i].first]) {
                DFSRecurList(g.adjList[source][i].first, target, visited, path);
            }
        }
    }
}

void RecursiveDFS::DFSRecurMatrix(int source, int target, vector<bool> &visited, vector<int> path) {
    visited[source] = true;
    path.push_back(source);
    this->numNodesExplored++;
    if (source == target) {
        this->finalPath = path;
        this->finalDistance = calculateDistance(path);
        this->finalCost = -1;
        return;
    } else {
        for (int i = 0; i < this->g.adjMatrix[source].size(); i++) {
            if (this->g.adjMatrix[source][i].first == 1) {
                if (!visited[i]) {
                    DFSRecurMatrix(i, target, visited, path);
                }
            }
        }
    }
}

double RecursiveDFS::calculateDistance(vector<int> path) {
    double distance = 0;
    for (int i = 0; i < path.size() - 1; i++) {
        distance = distance + this->g.adjMatrix[path[i]][path[i + 1]].second;
    }
    return distance;
}


void RecursiveDFS::SearchDataList(int source, int target, Graph g) {
    this->g = g;
    vector<bool> visited(g.adjList.size(), false);
    vector<int> path;
    DFSRecurList(source, target, visited, path);
}

void RecursiveDFS::SearchDataMatrix(int source, int target, Graph g) {
    this->g = g;
    vector<bool> visited(g.adjList.size(), false);
    vector<int> path;
    DFSRecurMatrix(source, target, visited, path);
}