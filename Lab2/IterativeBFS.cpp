//
// Created by Ryan on 10/13/19.
//

#include "IterativeBFS.h"

void IterativeBFS::BFSIter(int source, int target) {
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
            paths.push_back(path);
        }
        for (int i = 0; i < this->g.adjMatrix[lastNode].size(); i++) {
            if (isNotVisited(this->g.adjMatrix[lastNode][i].first, path)) {
                vector<int> newPath(path);
                newPath.push_back(this->g.adjMatrix[lastNode][i].first);
                queue.push(newPath);
            }
        }
    }
    this->finalPath = this->shortestPath(paths);
    //need to figure out cost
    if (this->finalPath.size() > 1) {
        for (int i = 1; i < this->finalPath.size(); i++) {
            this->finalCost = this->g.adjMatrix[i - 1][i].second;
        }
    } else {
        cout << "No path found" << endl;
    }
}

vector<int> IterativeBFS::shortestPath(vector<vector<int>> paths) {
    int shortestI = 0;
    for (int i = 1; i < paths.size(); i++) {
        if (paths[shortestI].size() > paths[i].size())
            shortestI = i;
    }
    return paths[shortestI];
}

int IterativeBFS::isNotVisited(int x, vector<int> &path) {
    for (int i = 0; i < path.size(); i++)
        if (path[i] == x)
            return 0;
    return 1;
}

void IterativeBFS::printShortestPath(vector<vector<int>> paths) {
    vector<int> path(paths.size());
    t = shortestPath(paths);
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << " ";
    }
    cout << endl;
}


void IterativeBFS::SearchData(int source, int target, Graph g) {
    this->g = g;
    this->startTime = chrono::high_resolution_clock::now();
    BFSIter(source, target);
    this->endTime = chrono::high_resolution_clock::now();
}
