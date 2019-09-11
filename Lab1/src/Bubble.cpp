//
// Created by Ryan on 9/8/19.
//

#include "Bubble.h"


void Bubble::SortData(int data[], int dataSize) {
    for (int i = 0; i < dataSize-1; i++) {
        for (int j = 0; j < dataSize-i-1; j++) {
            if (data[j] > data[j+1]) {
                swap(data[i], data[j+1]);
            }
        }
    }
}