//
// Created by Ryan on 10/1/19.
//

#ifndef LAB2_SEARCH_H
#define LAB2_SEARCH_H

#include <string>
#include "Algorithm.h"
#include <vector>
#include "SearchAlgorithm.h"
#include <fstream>
#include <sstream>
#include "Graph.h"
#include "RecursiveBFS.h"
#include "RecursiveDFS.h"
#include "IterativeBFS.h"
#include "IterativeDFS.h"
#include "Astar.h"
#include "Dijkstra.h"

class Search : public Algorithm {
public:
    Search();
    void Load(string fileName);

    void Execute();

    void Stats(string type);
    void Select(int sortAlgo);

    void Save(string filePath) {}

    void Display() {}
    void LoadManifest(string manifestFile);
    void Configure() {}
    vector<string> fileManifest;
    int numFiles;
    string activeSearchLabel;
    int numNodes;

    int generateRandomNode();
    enum SearchAlgo {
        DFSITER, DFSRECUR, BFSITER, BFSRECUR, DIJKSTRA, ASTAR, LAST
    };
    Graph graph;
    int start, end;
private:
    string dirPath;

    void outputStats(string dataType);
    SearchAlgorithm *searchAlgorithm;
};


#endif //LAB2_SEARCH_H
