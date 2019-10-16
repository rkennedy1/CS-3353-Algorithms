//
// Created by Ryan on 10/13/19.
//

#include "RecursiveDFS.h"

void RecursiveDFS::DFSRecur(int source, int target) {
    vector<bool> visited(g.adjList.size(), false);
    vector<int> path;
    DFSRecurUtil(source, target, visited, path);
}

void RecursiveDFS::DFSRecurUtil(int s, int t, vector<bool> &visited, vector<int> path) {
    visited[s] = true;
    path.push_back(s);
    this->numNodesExplored++;
    if (s == t) {
        this->finalPath = path;
        this->finalDistance = -1;
        this->finalCost = -1;
        return;
    } else {
        for (int i = 0; i < g.adjList[s].size(); i++) {
            if (!visited[g.adjList[s][i].first]) {
                DFSRecurUtil(g.adjList[s][i].first, t, visited, path);
            }
        }
    }
}

bool RecursiveDFS::isNotVisited(int x, vector<int> &path) {
    for (int i = 0; i < path.size(); i++)
        if (path[i] == x)
            return 0;
    return 1;
}

void RecursiveDFS::SearchDataList(int source, int target, Graph g) {
    this->g = g;
    DFSRecur(source, target);
}

void RecursiveDFS::SearchDataMatrix(int source, int target, Graph g) {
    this->g = g;
    DFSRecur(source, target);
}