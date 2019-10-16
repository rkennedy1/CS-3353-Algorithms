//
// Created by Ryan on 10/13/19.
//

#include "RecursiveBFS.h"

void RecursiveBFS::BFSRecurList(int source, int target) {
    vector<vector<int>> paths;
    vector<int> path;
    queue<vector<int>> q;
    vector<bool> visited(g.adjList.size(), false);
    for (int i = source; i < g.adjList.size(); i++) {
        if (visited[i] == false) {
            visited[i] = true;
            path.push_back(source);
            q.push(path);
            BFSRecurUtilList(target, q, visited, paths, path);
        }
    }
}

void
RecursiveBFS::BFSRecurUtilList(int target, queue<vector<int>> &q, vector<bool> &visited, vector<vector<int>> &paths,
                               vector<int> &path) {
    if (q.empty())
        return;
    path = q.front();
    q.pop();
    this->numNodesExplored++;
    int lastNode = path[path.size() - 1];
    if (lastNode == target) {
        this->finalPath = path;
        this->finalDistance = calculateDistance(path);
        this->finalCost = -1;
        return;
    }
    for (auto i : this->g.adjList[lastNode]) {
        if (!visited[i.first]) {
            vector<int> newPath(path);
            newPath.push_back(i.first);
            visited[i.first] = true;
            q.push(newPath);
        }
    }
    BFSRecurUtilList(target, q, visited, paths, path);
}

void RecursiveBFS::BFSRecurMatrix(int source, int target) {
    vector<vector<int>> paths;
    vector<int> path;
    queue<vector<int>> q;
    vector<bool> visited(g.adjMatrix.size(), false);
    for (int i = source; i < g.adjMatrix.size(); i++) {
        if (visited[i] == false) {
            visited[i] = true;
            path.push_back(source);
            q.push(path);
            BFSRecurUtilMatrix(target, q, visited, paths, path);
        }
    }
}

void
RecursiveBFS::BFSRecurUtilMatrix(int target, queue<vector<int>> &q, vector<bool> &visited, vector<vector<int>> &paths,
                                 vector<int> &path) {
    if (q.empty())
        return;
    path = q.front();
    q.pop();
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
                vector<int> newPath(path);
                newPath.push_back(i);
                visited[i] = true;
                q.push(newPath);
            }
        }
    }
    BFSRecurUtilMatrix(target, q, visited, paths, path);
}

double RecursiveBFS::calculateDistance(vector<int> path) {
    double distance = 0;
    for (int i = 0; i < path.size() - 1; i++) {
        distance += this->g.adjList[path[i]][path[i + 1]].second;
    }
    return distance;
}

void RecursiveBFS::SearchDataList(int source, int target, Graph g) {
    this->g = g;
    this->numNodesExplored = 0;
    BFSRecurList(source, target);
}

void RecursiveBFS::SearchDataMatrix(int source, int target, Graph g) {
    this->g = g;
    this->numNodesExplored = 0;
    BFSRecurMatrix(source, target);
}