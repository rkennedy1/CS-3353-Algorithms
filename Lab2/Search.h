//
// Created by Ryan on 10/1/19.
//

#ifndef LAB2_SEARCH_H
#define LAB2_SEARCH_H

#include <string>
#include "Algorithm.h"
#include <vector>
#include "myBFS.h"
#include "myDFS.h"
#include "SearchAlgorithm.h"
#include <fstream>
#include <sstream>
#include "Graph.h"
#include "RecursiveBFS.h"
#include "RecursiveDFS.h"
#include "IterativeBFS.h"
#include "IterativeDFS.h"

class Search {
public:
    Search();
    void Load(string fileName);
    void Execute();
    void Stats();
    void Select(int sortAlgo);
    void Save(string filePath);
    void Display();
    void LoadManifest(string manifestFile);
    void Configure() {}
    vector<string> fileManifest;
    int numFiles;
    string activeSearchLabel;

    //DIJKSTRA, ASTAR,
    enum SearchAlgo {
        DFSITER, DFSRECUR, BFSITER, BFSRECUR, LAST
    };
    Graph graph;

private:
    SearchAlgorithm *searchAlgorithm;
};


#endif //LAB2_SEARCH_H
