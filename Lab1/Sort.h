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


using namespace std;
class Sort : public Algorithm {
public:
    Sort();
    void Load(string fileName);
    void Execute();
    virtual void Stats();
    void Select(int sortAlgo);
    virtual void Save(string filePath);
    virtual void Display();
private:
    enum SortAlgo
    {
        BUBBLE, MERGE, INSERTION
    };
    int *data;
    int dataSize;
    string currentFile;
    int activeSortAlgo;
    string activeAlgoLabel;
    chrono::steady_clock::time_point start;
    chrono::steady_clock::time_point end;
    SortAlgorithm *sortAlgo;
};


#endif //LAB1_SORT_H
