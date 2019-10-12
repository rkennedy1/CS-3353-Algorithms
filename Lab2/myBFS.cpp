//
// Created by Ryan on 10/1/19.
//

#include "myBFS.h"

using namespace std;

myBFS::myBFS(Graph g) {
    this->g = g;
}

void myBFS::BFS(int source, int target) {
    if (source >= g.V || target >= g.V) {
        return;
    }
    vector<bool> visited(this->g.V, false);
    queue<int> queue;
    vector <vector<int>> parent;

    queue.push(source);
    visited[source] = true;

    while (!queue.empty()) {
        int currNode = queue.front();
        queue.pop();
        if (currNode == target) {
            //its done
        }
        for (auto i = this->g.adj[source].begin(); i != this->g.adj[source].end(); i++) {
            if (!visited[*i]) {
                visited[*i] = true;
                queue.push(*i);
                if (*i == target) {
                    cout << "Path: ";
                    printPath(parent[0], *i);
                    cout << endl;
                    return;
                }
            }
        }
    }
}

void myBFS::printPath(vector<int> parent, int i) {
    if (parent[i] == -1) {
        cout << i;
        return;
    }
    printPath(parent, parent[i]);
    cout << "->" << i;
}