//
// Created by Ryan on 10/13/19.
//

#include "RecursiveDFS.h"

void RecursiveDFS::DFSRecur(int source, int target) {
    vector<bool> visited(g.adjMatrix.size(), false);
    vector<int> path;
    vector<vector<int>> paths;
    DFSRecurUtil(source, target, visited, path, paths);
    printShortestPath(paths);
}

void RecursiveDFS::DFSRecurUtil(int s, int t, vector<bool> visited, vector<int> path, vector<vector<int>> &paths) {
    visited[s] = true;
    path.push_back(s);
    if (s == t) {
        paths.push_back(path);
    } else {
        for (auto i : g.adjMatrix[s]) {
            if (!visited[i.first]) {
                DFSRecurUtil(i.first, t, visited, path, paths);
            }
        }
    }
}

vector<int> RecursiveDFS::shortestPath(vector<vector<int>> paths) {
    int shortestI = 0;
    for (int i = 1; i < paths.size(); i++) {
        if (paths[shortestI].size() > paths[i].size())
            shortestI = i;
    }
    return paths[shortestI];
}

void RecursiveDFS::printShortestPath(vector<vector<int>> paths) {
    vector<int> path(paths.size());
    path = shortestPath(paths);
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << " ";
    }
    cout << endl;
}

void RecursiveDFS::SearchData(int source, int target, Graph g) {
    this->g = g;
    DFSRecur(source, target);
}
