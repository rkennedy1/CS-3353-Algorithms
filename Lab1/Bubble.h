//
// Created by Ryan on 9/8/19.
//

#ifndef LAB1_BUBBLE_H
#define LAB1_BUBBLE_H


#include "Sort.h"

class Bubble: public Sort {
private:
    void swap(int* left, int* right);
public:
    void SortData(int data[], int dataSize);
};


#endif //LAB1_BUBBLE_H
