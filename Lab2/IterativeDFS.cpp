//
// Created by Ryan on 10/13/19.
//

#include "IterativeDFS.h"

void IterativeDFS::DFSIter(int source, int target) {
    stack<vector<int>> stack;
    vector<int> path;
    vector<vector<int>> paths;

    path.push_back(source);
    stack.push(path);

    while (!stack.empty()) {
        path = stack.top();
        stack.pop();

        int last = path[path.size() - 1];
        if (last == target) {
            paths.push_back(path);
        }
        for (int i = 0; i < this->g.adjMatrix[last].size(); i++) {
            if (isNotVisited(this->g.adjMatrix[last][i], path)) {
                vector<int> newPath(path);
                newPath.push_back(this->g.adjMatrix[last][i]);
                stack.push(newPath);
            }
        }
    }
    printShortestPath(paths);
}

int IterativeDFS::isNotVisited(int x, vector<int> &path) {
    for (int i = 0; i < path.size(); i++)
        if (path[i] == x)
            return 0;
    return 1;
}

vector<int> IterativeDFS::shortestPath(vector<vector<int>> paths) {
    int shortestI = 0;
    for (int i = 1; i < paths.size(); i++) {
        if (paths[shortestI].size() > paths[i].size())
            shortestI = i;
    }
    return paths[shortestI];
}

void IterativeDFS::printShortestPath(vector<vector<int>> paths) {
    vector<int> path(paths.size());
    path = shortestPath(paths);
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << " ";
    }
    cout << endl;
}

void IterativeDFS::SearchData(int source, int target, Graph g) {
    this->g = g;
    DFSIter(source, target);
}
