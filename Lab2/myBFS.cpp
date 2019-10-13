//
// Created by Ryan on 10/1/19.
//

#include "myBFS.h"

using namespace std;

myBFS::myBFS(vector<vector<int>> g) {
    this->g = g;
}

void myBFS::BFSIter(int source, int target) {
    queue<vector<int>> queue;
    vector<int> path;
    vector<vector<int>> paths;


    path.push_back(source);
    queue.push(path);

    while (!queue.empty()) {
        path = queue.front();
        queue.pop();

        int last = path[path.size() - 1];
        if (last == target) {
            paths.push_back(path);
        }
        for (int i = 0; i < this->g[last].size(); i++) {
            if (isNotVisited(this->g[last][i], path)) {
                vector<int> newPath(path);
                newPath.push_back(this->g[last][i]);
                queue.push(newPath);
            }
        }
    }
    cout << "Shortest path is: " << endl;
    printPath(shortestPath(paths));
}

vector<int> myBFS::shortestPath(vector<vector<int>> paths) {
    int shortestI = 0;
    for (int i = 1; i < paths.size(); i++) {
        if (paths[shortestI].size() > paths[i].size())
            shortestI = i;
    }
    return paths[shortestI];
}

int myBFS::isNotVisited(int x, vector<int> &path) {
    for (int i = 0; i < path.size(); i++)
        if (path[i] == x)
            return 0;
    return 1;
}

void myBFS::printPath(vector<int> path) {
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << " ";
    }
    cout << endl;
}