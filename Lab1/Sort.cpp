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
Sort::Sort() {

}

void Sort::Load(string fileName) {
    ifstream inputFile;
    inputFile.open(fileName);
    string tempFileName;
    int dataSize;
    while (!(inputFile.eof())) {
        getline(inputFile, tempFileName);
        size_t pos = tempFileName.find("-");
        string dataSizeStr = tempFileName.substr(0, pos);
        dataSize = stoi(dataSizeStr);
        ifstream myFile;
        myFile.open(tempFileName);
        data = new int[dataSize];
        string temp;
        int i = 0;
        while(!(myFile.eof())) {
            getline(myFile, temp, ',');
            data[i] = stoi(temp);
            i++;
        }
        //Execute(data);
//        for (int i = 0; i < dataSize; i++) {
//            cout << data[i] << " ";
//        }
        Insertion I;
        auto start = chrono::high_resolution_clock::now();
        I.SortData(data, dataSize);
        auto end = chrono::high_resolution_clock::now();
        double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
        time_taken *= 1e-9;
        cout << "Time taken by " << tempFileName << " using Insertion Sort is : " << fixed << time_taken << setprecision(9);
        cout << " sec" << endl;
        Bubble b;
        auto bubbleStart = chrono::high_resolution_clock::now();
        b.SortData(data, dataSize);
        auto bubbleEnd = chrono::high_resolution_clock::now();
        double time_taken2 = chrono::duration_cast<chrono::nanoseconds>(bubbleEnd - bubbleStart).count();
        time_taken2 *= 1e-9;
        cout << "Time taken by " << tempFileName << " using Bubble Sort is : " << fixed << time_taken2 << setprecision(9);
        cout << " sec" << endl;
//        for (int i = 0; i < dataSize; i++) {
//            cout << data[i] << " ";
//        }
    }

}
/*
void Algorithm::Execute(int data[]) {

}

void Algorithm::Display() {

}

void Algorithm::Stats() {

}

void Algorithm::Select() {

}

void Algorithm::Save(string filePath) {

}*/