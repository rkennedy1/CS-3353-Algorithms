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
#include <chrono>
#include <iomanip>
#include "SortAlgorithm.h"

Sort::Sort() {
    activeSortAlgo=2;
}

void Sort::Load(string inputFileName) {
    ifstream inputFile;
    currentFile = inputFileName;
    inputFile.open(currentFile);
    size_t pos = currentFile.find("-");
    string dataSizeStr = currentFile.substr(0, pos);
    this->dataSize = stoi(dataSizeStr);
    ifstream myFile;
    myFile.open(currentFile);
    int tempSize = dataSize;
    int tempData[tempSize];
    string temp;
    int i = 0;
    while(!(myFile.eof())) {
        getline(myFile, temp, ',');
        tempData[i] = stoi(temp);
        i++;
    }
    data = tempData;
}

void Sort::Execute() {
    SortAlgorithm *sortAlgo;
    string activeAlgoLabel;
    switch (activeSortAlgo)
    {
        case 1: sortAlgo = new Insertion;
        activeAlgoLabel = "Insertion Sort";
            break;
        case 2: sortAlgo = new Bubble;
        activeAlgoLabel = "Bubble Sort";
            break;
    }
    auto start = chrono::high_resolution_clock::now();
    sortAlgo->SortData(data, dataSize);
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "Time taken by " << currentFile << " using " << activeAlgoLabel << " is : " << fixed << time_taken << setprecision(9);
    cout << " sec" << endl;
}

void Sort::Select(int sortAlgo) {
    activeSortAlgo = sortAlgo;
}

void Sort::Save(string filePath) {
    ofstream outputFile;
    outputFile.open(filePath);
    for (int i = 0; i < dataSize; i++) {
        outputFile << data[i] << " ";
    }
    outputFile.close();
}

/*
void Sort::Display() {

}

void Algorithm::Stats() {

}

*/