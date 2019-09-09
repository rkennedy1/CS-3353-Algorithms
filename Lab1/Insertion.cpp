//
// Created by Ryan on 9/8/19.
//

#include "Insertion.h"

void Insertion::SortData(int data[], int dataSize) {
    int i, j, key;
    for (i = 1; i < dataSize; i++) {
        key = data[i];
        j = i - 1;
        while (j >= 0 && data[j] > key) {
            data[j+1] = data[j];
            j = j-1;
        }
        data[j+1] = key;
    }
}