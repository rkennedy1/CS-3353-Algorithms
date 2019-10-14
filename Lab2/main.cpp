#include <iostream>
#include "Graph.h"
#include "myDFS.h"
#include "myBFS.h"
#include "Search.h"

using namespace std;

int main() {
    Search s;
    s.LoadManifest("fileManifest.txt");
    for (int i = s.DFSITER; i < s.LAST; i++) {
        for (int j = 0; j < s.numFiles - 1; j++) {
            s.Load(s.fileManifest[j]);
            s.Select(i);
            s.Execute();
        }
    }
    int src = 0, dst = 6;
    cout << "BFSIter iter path from src " << src
         << " to dst " << dst << " are \n";
    cout << "BFS recur path from src " << src
         << " to dst " << dst << " are \n";
    cout << "DFS iter path from src " << src
         << " to dst " << dst << " are \n";
    cout << "DFS recur path from src " << src
         << " to dst " << dst << " are \n";
    return 0;
}
/*    vector<vector<int>> g;
    g.resize(9);

    // construct a graph
    //g[0].push_back(3);
    g[0].push_back(1);
    g[0].push_back(2);
    g[1].push_back(3);
    g[2].push_back(0);
    g[2].push_back(1);
    g[2].push_back(4);
    g[3].push_back(5);
    g[4].push_back(5);
    g[4].push_back(6);
    g[5].push_back(7);
    g[5].push_back(8);
    g[6].push_back(3);
    g[6].push_back(7);
    g[7].push_back(6);
    g[7].push_back(8);
*/