//
// Created by Ryan on 9/8/19.
//

#include "Sort.h"


Sort::Sort() {
    sortAlgorithm = new Merge;
    activeAlgoLabel = "Merge Sort";
    numFiles = 0;
}

void Sort::Load(string inputFileName) {
    ifstream inputFile;
    currentFile = inputFileName;
    inputFile.open(currentFile);

    // Retrieving the size of file delimited by dash from the file name
    size_t pos = currentFile.find("-");
    string dataSizeStr = currentFile.substr(0, pos);
    dataSize = stoi(dataSizeStr);

    int *tempData;
    tempData = new int[dataSize];
    string temp;
    int i = 0;
    while(!(inputFile.eof())) {
        getline(inputFile, temp, ',');
        tempData[i] = stoi(temp);
        i++;
    }
    data = new int[dataSize];
    data = tempData;
}

void Sort::Execute() {
    start = chrono::high_resolution_clock::now();
    sortAlgorithm->SortData(data, dataSize);
    end = chrono::high_resolution_clock::now();
}

void Sort::Select(int sortAlgoInput) {
    switch (sortAlgoInput)
    {
        case INSERTION: sortAlgorithm = new Insertion;
            activeAlgoLabel = "Insertion";
            break;
        case BUBBLE: sortAlgorithm = new Bubble;
            activeAlgoLabel = "Bubble";
            break;
        case MERGE: sortAlgorithm = new Merge;
            activeAlgoLabel = "Merge";
            break;
    }
}

void Sort::Save(string filePath) {
    size_t pos = filePath.find(".csv");
    string filePathWithoutExtn = filePath.substr(0, pos);
    ofstream outputFile;
    outputFile.open(filePathWithoutExtn+"-"+activeAlgoLabel+"-Solved.txt");
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

//used http://www.cplusplus.com/reference/chrono/high_resolution_clock/ for reference on high res timer
void Sort::Stats() {
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "Time taken by " << currentFile << " using " << activeAlgoLabel << " sort is : " << fixed << time_taken << setprecision(9);
    cout << " sec" << endl;
}

void Sort::LoadManifest(string manifestFile) {
    ifstream inputFile;
    inputFile.open(manifestFile);
    string currentFileName;
    while (!(inputFile.eof())) {
        getline(inputFile, currentFileName);
        fileManifest.push_back(currentFileName);
        numFiles++;
    }
}
