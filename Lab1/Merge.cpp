//
// Created by Ryan on 9/8/19.
//

#include "Merge.h"

void Merge::merge(int data[], int leftIndex, int middle, int rightIndex) {
    int sortedData[rightIndex - leftIndex + 1];
    int i = leftIndex;
    int j = middle+1;
    int k = 0;
    while (i <= middle && j <= rightIndex) {
        if (data[i] <= data[j]) {
            sortedData[k] = data[i];
            k++;
            i++;
        } else {
            sortedData[k] = data[j];
            k++;
            j++;
        }
    }

    //copying remaining values to sorted array
    while (i <= middle) {
        sortedData[k] = data[i];
        k++;
        i++;
    }

    while (j <= rightIndex) {
        sortedData[k] = data[j];
        k++;
        j++;
    }
    for (i = leftIndex, k=0; i <= rightIndex; i++,k++) {
        data[i] = sortedData[k];
    }
}

void Merge::MergeSort(int *data, int leftIndex, int rightIndex) {
    if (leftIndex < rightIndex) {
        int middle = (leftIndex+rightIndex)/2;
        MergeSort(data, leftIndex, middle);
        MergeSort(data, middle+1, rightIndex);
        merge(data, leftIndex, middle, rightIndex);
    }
}

void Merge::SortData(int data[], int dataSize) {
    int sortData[dataSize];
    int i;
    for ( i = 0; i < dataSize; i++) {
        sortData[i] = data[i];
    }
    MergeSort(sortData, 0, dataSize-1);
    for (i = 0; i < dataSize; i++) {
        data[i] = sortData[i];
    }
}