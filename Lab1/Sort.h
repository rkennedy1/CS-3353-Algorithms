//
// Created by Ryan on 9/8/19.
//

#ifndef LAB1_SORT_H
#define LAB1_SORT_H


#include "Algorithm.h"
#include <string>
#include <vector>

using namespace std;
class Sort : public Algorithm {
public:
    Sort();
    void Load(string fileName);
    void Execute();
    //virtual void Stats();
    void Select(int sortAlgo);
    virtual void Save(string filePath);
private:
    enum SortAlgo
    {
        BUBBLE, MERGE, INSERTION
    };
    int *data;
    int dataSize;
    string currentFile;
    int activeSortAlgo;
    void LoadData(int index);
};


#endif //LAB1_SORT_H
