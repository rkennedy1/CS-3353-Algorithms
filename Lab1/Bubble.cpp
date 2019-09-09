//
// Created by Ryan on 9/8/19.
//

#include "Bubble.h"
#include <chrono>
#include <ctime>

void Bubble::swap(int *left, int *right) {
    int temp = *left;
    *left = *right;
    *right = temp;
}

void Bubble::SortData(int data[], int dataSize) {
    //std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    int i, j;
    for (i = 0; i < dataSize-1; i++) {
        for (j = 0; j < dataSize-i-1; j++) {
            if (data[j] > data[j+1]) {
                swap(&data[j], &data[j+1]);
            }
        }
    }
    //std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    //std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
}