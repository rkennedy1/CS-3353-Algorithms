//
// Created by Ryan on 10/2/19.
//

#include "myDFS.h"


using namespace std;

myDFS::myDFS(vector<vector<int>> graph) {
    this->graph = graph;
}

void myDFS::DFSRecur(int source, int target) {
    vector<bool> visited(graph.size(), false);
    vector<int> path;
    vector<vector<int>> paths;
    DFSRecurUtil(source, target, visited, path, paths);
    printShortestPath(paths);
}

void
myDFS::DFSRecurUtil(int s, int t, vector<bool> visited, vector<int> path, vector<vector<int>> &paths) {
    visited[s] = true;
    path.push_back(s);
    if (s == t) {
        paths.push_back(path);
    } else {
        for (int i : graph[s]) {
            if (!visited[i]) {
                DFSRecurUtil(i, t, visited, path, paths);
            }
        }
    }
}

void myDFS::DFSIter(int source, int target) {
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
        for (int i = 0; i < this->graph[last].size(); i++) {
            if (isNotVisited(this->graph[last][i], path)) {
                vector<int> newPath(path);
                newPath.push_back(this->graph[last][i]);
                stack.push(newPath);
            }
        }
    }
    printShortestPath(paths);
}

vector<int> myDFS::shortestPath(vector<vector<int>> paths) {
    int shortestI = 0;
    for (int i = 1; i < paths.size(); i++) {
        if (paths[shortestI].size() > paths[i].size())
            shortestI = i;
    }
    return paths[shortestI];
}


int myDFS::isNotVisited(int x, vector<int> &path) {
    for (int i = 0; i < path.size(); i++)
        if (path[i] == x)
            return 0;
    return 1;
}

void myDFS::printShortestPath(vector<vector<int>> paths) {
    vector<int> path(paths.size());
    path = shortestPath(paths);
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << " ";
    }
    cout << endl;
}
