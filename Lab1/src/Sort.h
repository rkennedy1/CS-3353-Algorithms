//
// Created by Ryan on 9/8/19.
//

#ifndef LAB1_SORT_H
#define LAB1_SORT_H


#include "Algorithm.h"
#include <string>
#include <vector>
#include <chrono>
#include "SortAlgorithm.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "Bubble.h"
#include "Insertion.h"
#include "Merge.h"
#include <iomanip>
#include "SortAlgorithm.h"


using namespace std;
class Sort : public Algorithm {
public:
    Sort();

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
    enum SortAlgo
    {
        INSERTION, BUBBLE, MERGE, LAST
    };
private:
    int *data;
    int dataSize;
    string currentFile;
    SortAlgorithm *sortAlgorithm;
    chrono::steady_clock::time_point start;
    chrono::steady_clock::time_point end;
};


#endif //LAB1_SORT_H
