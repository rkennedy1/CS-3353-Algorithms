#include <iostream>
#include "Graph.h"
#include "myDFS.h"
#include "myBFS.h"
#include "Search.h"
#include "Dijkstra.h"

using namespace std;

int main(int argc, char *argv[]) {
    Search s;
    s.LoadManifest("fileManifest.txt");
    /*
    for (int i = s.DFSITER; i < s.LAST; i++) {
        for(int j = 0; j < s.numFiles; j++) {
            s.Load(s.fileManifest[j]);
            s.Select(i);
            s.Execute();
        }
    }*/
    s.Load(s.fileManifest[0]);
    Dijkstra d;
    int node = stoi(argv[1]);
    vector<int> dist = d.DijkstraSP(s.graph.adjMatrix, node);
    d.PrintShortestPath(dist, node);

    return 0;
}
/*
int main() {

    vector<vector<int>> g;
    g.resize(9);

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


    Search s;
    //s.LoadManifest("fileManifest.txt");
    //s.Load(s.fileManifest[0]);
    RecursiveBFS b;
    Graph q;
    q.loadGraphs(g);
    b.SearchData(0, 8, q);

}*/
