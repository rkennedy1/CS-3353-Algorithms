#include <iostream>
#include "Graph.h"
#include "myDFS.h"
#include "myBFS.h"

using namespace std;

int main() {
    Graph list(4);
    list.addEdge(0, 1);
    list.addEdge(0, 2);
    list.addEdge(0, 3);
    list.addEdge(1, 2);
    list.addEdge(2, 0);
    //list.addEdge(2, 3);
    list.addEdge(3, 3);
    /*Graph q(4);
    q.addEdge(0, 1);
    q.addEdge(0, 2);
    q.addEdge(1, 2);
    q.addEdge(2, 0);
    q.addEdge(2, 3);
    q.addEdge(3, 3);*/

    vector<vector<int> > g;
    g.resize(4);

    // construct a graph
    //g[0].push_back(3);
    g[0].push_back(1);
    g[0].push_back(2);
    g[1].push_back(3);
    g[2].push_back(0);
    g[2].push_back(1);

    int src = 0, dst = 3;
    cout << "BFSIter iter path from src " << src
         << " to dst " << dst << " are \n";
    myBFS b(g);
    b.BFSIter(src, dst);
    cout << "DFS iter path from src " << src
         << " to dst " << dst << " are \n";
    myDFS d(list, g);
    d.DFSIter(src, dst);
    cout << "DFS recur path from src " << src
         << " to dst " << dst << " are \n";
    d.DFSRecur(src, dst);
    return 0;
}