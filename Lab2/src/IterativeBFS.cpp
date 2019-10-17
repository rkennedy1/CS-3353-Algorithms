//
// Created by Ryan on 10/13/19.
//

#include "IterativeBFS.h"

void IterativeBFS::BFSIterList(int source, int target) {
    vector<bool> visited(g.adjList.size(), false);
    queue<vector<int>> queue;
    vector<int> path;
    vector<vector<int>> paths;

    path.push_back(source);
    queue.push(path);

    while (!queue.empty()) {
        path = queue.front();
        queue.pop();
        this->numNodesExplored++;

        int lastNode = path[path.size() - 1];
        if (lastNode == target) {
            this->finalPath = path;
            this->finalDistance = calculateDistance(path);
            this->finalCost = -1;
            return;
        }
        for (int i = 0; i < this->g.adjList[lastNode].size(); i++) {
            if (!visited[this->g.adjList[lastNode][i].first]) {
                visited[this->g.adjList[lastNode][i].first] = true;
                vector<int> newPath(path);
                newPath.push_back(this->g.adjList[lastNode][i].first);
                queue.push(newPath);
            }
        }
    }
}

void IterativeBFS::BFSIterMatrix(int source, int target) {
    queue<vector<int>> queue;
    vector<int> path;
    vector<vector<int>> paths;
    vector<bool> visited(g.adjMatrix.size(), false);


    path.push_back(source);
    queue.push(path);

    while (!queue.empty()) {
        path = queue.front();
        queue.pop();
        this->numNodesExplored++;
        int lastNode = path[path.size() - 1];
        if (lastNode == target) {
            this->finalPath = path;
            this->finalDistance = calculateDistance(path);
            this->finalCost = -1;
            return;
        }
        for (int i = 0; i < this->g.adjMatrix[lastNode].size(); i++) {
            if (this->g.adjMatrix[lastNode][i].first == 1) {
                if (!visited[i]) {
                    visited[i] = true;
                    vector<int> newPath(path);
                    newPath.push_back(i);
                    queue.push(newPath);
                }
            }
        }
    }
}

double IterativeBFS::calculateDistance(vector<int> path) {
    double distance = 0;
    for (int i = 0; i < path.size() - 1; i++) {
        distance = distance + this->g.adjMatrix[path[i]][path[i + 1]].second;
    }
    return distance;
}


void IterativeBFS::SearchDataList(int source, int target, Graph g) {
    this->g = g;
    this->numNodesExplored = 0;
    BFSIterList(source, target);
}

void IterativeBFS::SearchDataMatrix(int source, int target, Graph g) {
    this->g = g;
    this->numNodesExplored = 0;
    BFSIterMatrix(source, target);
}