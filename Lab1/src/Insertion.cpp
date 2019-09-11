//
// Created by Ryan on 9/8/19.
//

#include "Insertion.h"

void Insertion::SortData(int data[], int dataSize) {
    for (int i = 1; i < dataSize; i++) {
        int j = i - 1;
        int key = data[i];
        while (j >= 0 && data[j] > key) {
            data[j+1] = data[j];
            j--;
        }
        data[j+1] = key;
    }
}