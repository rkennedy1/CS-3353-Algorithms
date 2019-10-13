//
// Created by Ryan on 10/1/19.
//

#ifndef LAB2_SEARCH_H
#define LAB2_SEARCH_H

#include <string>
#include "Algorithm.h"
#include <vector>

class Search : public Algorithm {
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
    string activeAlgoLabel;
    enum SearchAlgo {
        DFSITER, DFSRECUR, BFSITER, BFSRECUR, DIJKSTRA, ASTAR, LAST
    };
};


#endif //LAB2_SEARCH_H
