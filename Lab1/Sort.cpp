//
// Created by Ryan on 9/8/19.
//

#include "Sort.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "Bubble.h"
#include "Insertion.h"
#include "Merge.h"
#include <iomanip>
#include "SortAlgorithm.h"



Sort::Sort() {
    activeSortAlgo=1;
}

void Sort::Load(string inputFileName) {
    ifstream inputFile;
    currentFile = inputFileName;
    inputFile.open(currentFile);
    size_t pos = currentFile.find("-");
    string dataSizeStr = currentFile.substr(0, pos);
    dataSize = stoi(dataSizeStr);
    ifstream myFile;
    myFile.open(currentFile);
    int *tempData;
    tempData = new int [dataSize];
    string temp;
    int i = 0;
    while(!(myFile.eof())) {
        getline(myFile, temp, ',');
        tempData[i] = stoi(temp);
        i++;
    }
    data = new int[dataSize];
    data = tempData;
}

void Sort::Execute() {
    start = chrono::high_resolution_clock::now();
    sortAlgo->SortData(data, dataSize);
    end = chrono::high_resolution_clock::now();
}

void Sort::Select(int sortAlgoInput) {
    activeSortAlgo = sortAlgoInput;
    switch (activeSortAlgo)
    {
        case 1: sortAlgo = new Insertion;
            activeAlgoLabel = "Insertion Sort";
            break;
        case 2: sortAlgo = new Bubble;
            activeAlgoLabel = "Bubble Sort";
            break;
        case 3: sortAlgo = new Merge;
            activeAlgoLabel = "Merge Sort";
            break;
    }
}

void Sort::Save(string filePath) {
    ofstream outputFile;
    outputFile.open(filePath);
    for (int i = 0; i < dataSize; i++) {
        outputFile << data[i] << " ";
    }
    outputFile.close();
    delete[] data;
}


void Sort::Display() {
    for (int i = 0; i < dataSize; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}


void Sort::Stats() {
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "Time taken by " << currentFile << " using " << activeAlgoLabel << " is : " << fixed << time_taken << setprecision(9);
    cout << " sec" << endl;
}
