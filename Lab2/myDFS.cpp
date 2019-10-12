//
// Created by Ryan on 10/2/19.
//

#include "myDFS.h"


using namespace std;

myDFS::myDFS(Graph g) {
    this->g = g;
}

void myDFS::DFSRecur(int source, int target) {
    vector<bool> visited(this->g.V, false);
    int *path = new int[this->g.V];
    int path_index = 0;
    DFSRecurUtil(source, target, visited, path, path_index);
}

/*
    stack<int> stack;
    stack.push(source);

    while(!stack.empty()) {
        source = stack.top();
        stack.pop();
        if (!visited[source]) {
            visited[source] = true;
        }
        for (auto i = this->g.adj[source].begin(); i != this->g.adj[source].end(); i++) {
            if (!visited[*i]) {
                stack.push(*i);
            }
        }
    }*/


void myDFS::DFSRecurUtil(int s, int t, vector<bool> visited, int *path, int path_index) {
    visited[s] = true;
    path[path_index] = s;
    path_index++;
    if (s == t) {
        for (int i = 0; i < path_index; i++) {
            cout << path[i] << " ";
        }
        cout << endl;
    } else {
        for (auto i = this->g.adj[s].begin(); i != this->g.adj[s].end(); i++) {
            if (!visited[*i]) {
                DFSRecurUtil(*i, t, visited, path, path_index);
            }
        }
    }
    path_index--;
    visited[s] = false;
}


void myDFS::DFS(int source, vector<bool> visited) {
    visited[source] = true;
    cout << source << " ";
    for (auto i = this->g.adj[source].begin(); i != this->g.adj[source].end(); i++) {
        if (!visited[*i]) {
            DFS(*i, visited);
        }
    }
}

void myDFS::DFSUtil(int source) {
    vector<bool> visited(g.V, false);
    DFS(source, visited);
}

void myDFS::printPath(vector<int> parent, int i) {
    if (parent[i] == -1) {
        cout << i;
        return;
    }
    printPath(parent, parent[i]);
    cout << "->" << i;
}