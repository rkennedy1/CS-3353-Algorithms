//
// Created by Ryan on 10/13/19.
//

#include "RecursiveBFS.h"

void RecursiveBFS::BFSRecur(int source, int target) {
    vector<vector<int>> paths;
    vector<int> path;
    queue<int> q;
    vector<bool> visited(g.adjMatrix.size(), false);
    for (int i = source; i < g.adjMatrix.size(); i++) {
        if (visited[i] == false) {
            visited[i] = true;
            q.push(i);
            BFSRecurUtil(target, q, visited, paths, path);
        }
    }
    printShortestPath(paths);
}

void RecursiveBFS::BFSRecurUtil(int target, queue<int> &q, vector<bool> &visited, vector<vector<int>> &paths,
                                vector<int> &path) {
    if (q.empty())
        return;
    int s = q.front();
    path.push_back(s);
    q.pop();
    if (s == target) {
        paths.push_back(path);
        path.clear();
    }
    for (int i : this->g.adjMatrix[s]) {
        if (!visited[i]) {
            visited[i] = true;
            q.push(i);
        }
    }
    BFSRecurUtil(target, q, visited, paths, path);
}

vector<int> RecursiveBFS::shortestPath(vector<vector<int>> paths) {
    int shortestI = 0;
    for (int i = 1; i < paths.size(); i++) {
        if (paths[shortestI].size() > paths[i].size())
            shortestI = i;
    }
    return paths[shortestI];
}

void RecursiveBFS::printShortestPath(vector<vector<int>> paths) {
    vector<int> path(paths.size());
    path = shortestPath(paths);
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << " ";
    }
    cout << endl;
}

void RecursiveBFS::SearchData(int source, int target, Graph g) {
    this->g = g;
    BFSRecur(source, target);
}
