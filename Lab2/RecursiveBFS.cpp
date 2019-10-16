//
// Created by Ryan on 10/13/19.
//

#include "RecursiveBFS.h"

void RecursiveBFS::BFSRecur(int source, int target) {
    vector<vector<int>> paths;
    vector<int> path;
    queue<vector<int>> q;
    vector<bool> visited(g.adjList.size(), false);
    for (int i = source; i < g.adjList.size(); i++) {
        if (visited[i] == false) {
            visited[i] = true;
            path.push_back(source);
            q.push(path);
            BFSRecurUtil(target, q, visited, paths, path);
        }
    }
}

void RecursiveBFS::BFSRecurUtil(int target, queue<vector<int>> &q, vector<bool> &visited, vector<vector<int>> &paths,
                                vector<int> &path) {
    if (q.empty())
        return;
    path = q.front();
    q.pop();
    this->numNodesExplored++;
    int lastNode = path[path.size() - 1];
    if (lastNode == target) {
        this->finalPath = path;
        this->finalDistance = -1;
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
    BFSRecurUtil(target, q, visited, paths, path);
}

void RecursiveBFS::SearchDataList(int source, int target, Graph g) {
    this->g = g;
    this->numNodesExplored = 0;
    BFSRecur(source, target);
}

void RecursiveBFS::SearchDataMatrix(int source, int target, Graph g) {
    this->g = g;
    this->numNodesExplored = 0;
    BFSRecur(source, target);
}