//
// Created by Ryan on 10/13/19.
//

#include "IterativeDFS.h"

void IterativeDFS::DFSIterList(int source, int target) {
    stack<vector<int>> stack;
    vector<int> path;
    vector<vector<int>> paths;
    vector<bool> visited(g.adjList.size(), false);

    path.push_back(source);
    stack.push(path);

    while (!stack.empty()) {
        path = stack.top();
        stack.pop();
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
                stack.push(newPath);
            }
        }
    }
    cout << endl;
}

void IterativeDFS::DFSIterMatrix(int source, int target) {
    stack<vector<int>> stack;
    vector<int> path;
    vector<vector<int>> paths;
    vector<bool> visited(g.adjMatrix.size(), false);

    path.push_back(source);
    stack.push(path);

    while (!stack.empty()) {
        path = stack.top();
        stack.pop();
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
                    stack.push(newPath);
                }
            }
        }
    }
    cout << endl;
}

double IterativeDFS::calculateDistance(vector<int> path) {
    double distance = 0;
    for (int i = 0; i < path.size() - 1; i++) {
        distance += this->g.adjList[path[i]][path[i + 1]].second;
    }
    if (!distance) {
        distance = 0;
    }
    return distance;
}

void IterativeDFS::SearchDataList(int source, int target, Graph g) {
    this->g = g;
    this->numNodesExplored = 0;
    DFSIterList(source, target);
}

void IterativeDFS::SearchDataMatrix(int source, int target, Graph g) {
    this->g = g;
    this->numNodesExplored = 0;
    DFSIterMatrix(source, target);
}