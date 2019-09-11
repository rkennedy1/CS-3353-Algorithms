//
// Created by Ryan on 9/8/19.
//

#ifndef LAB1_MERGE_H
#define LAB1_MERGE_H


#include "Sort.h"
#include "SortAlgorithm.h"

class Merge: public SortAlgorithm {
private:
    void merge(int data[], int leftIndex, int middle, int rightIndex);
    void MergeSort(int data[], int leftIndex, int rightIndex);
public:
    void SortData(int data[], int dataSize);
};


#endif //LAB1_MERGE_H
