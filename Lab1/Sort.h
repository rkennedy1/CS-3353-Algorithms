//
// Created by Ryan on 9/8/19.
//

#ifndef LAB1_SORT_H
#define LAB1_SORT_H


#include "Algorithm.h"
#include <string>

using namespace std;
class Sort : public Algorithm {
public:
    Sort();
    void Load(string fileName);
    virtual void SortData(int data[], int dataSize) = 0;
    //virtual void Stats();
    //virtual void Select();
    //virtual void Save(string filePath);
public:
    int *data;
};


#endif //LAB1_SORT_H
