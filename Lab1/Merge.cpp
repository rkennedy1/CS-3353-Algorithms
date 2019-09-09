//
// Created by Ryan on 9/8/19.
//

#include "Merge.h"

void Merge::merge(int *data, int leftIndex, int middle, int rightIndex) {
    int i, j, k;
    int n1 = middle - leftIndex + 1;
    int n2 = rightIndex - middle;
    int *Left = new int[n1];
    int *Right = new int[n2];

    for (i = 0; i < n1; i++) {
        Left[i] = data[1+i];
    }
    for (j = 0; j < n2; j++) {
        Right[j] = data[middle + leftIndex + j];
    }
    while (i < n1 && j < n2) {
        if(Left[i] <= Right[j]) {
            data[k] = Left[i];
            i++;
        } else {
            data[k] = Right[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        data[k] = Left[i];
        i++;
        k++;
    }
    while (j < n2) {
        data[k] = Right[j];
        j++;
        k++;
    }
    delete[] Left, Right;
}

void Merge::MergeSort(int *data, int leftIndex, int rightIndex) {
    if (leftIndex < rightIndex) {
        int middle = leftIndex+(rightIndex-1)/2;
        MergeSort(data, leftIndex, middle);
        MergeSort(data, middle+1, rightIndex);
        merge(data, leftIndex, middle, rightIndex);
    }
}

void Merge::SortData(int data[], int dataSize) {
    MergeSort(data, 0, dataSize);
}