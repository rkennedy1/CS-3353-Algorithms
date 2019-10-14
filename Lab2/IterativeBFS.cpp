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
    printShortestPath(paths);
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
    path = shortestPath(paths);
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << " ";
    }
    cout << endl;
}


void IterativeBFS::SearchData(int source, int target, Graph g) {
    this->g = g;
    BFSIter(source, target);
}
