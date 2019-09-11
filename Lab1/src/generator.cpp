//
// Created by Ryan on 9/4/19.
//
#include "generator.h"

Generator::Generator() {
}

void Generator::generateFullyRandom(int dataSize) {
    int randomNum;
    int data[dataSize];
    srand (time(NULL));
    for (int i = 0; i < dataSize; i++) {
        randomNum = rand() % dataSize + 1;
        data[i] = randomNum;
    }
    stringstream fileName;
    fileName << dataSize << "-FullyRandom.csv";
    fileManifest.push_back(fileName.str());
    printToFile(data, dataSize, fileName.str());
}

void Generator::generateReverseSortedOrder(int dataSize) {
    int data[dataSize];
    for (int i = 0; i < dataSize; i++) {
        data[i] = dataSize-i;
    }
    stringstream fileName;
    fileName << dataSize << "-ReverseSortedOrder.csv";
    fileManifest.push_back(fileName.str());
    printToFile(data, dataSize, fileName.str());
}

void Generator::generatePartialRandomized(int dataSize) {
    int data[dataSize];
    int i, randomNum;
    srand (time(NULL));
    for (i = 0; i < ((dataSize/10)*7); i++) {
        data[i] = i;
    }
    for (int j = i; j< dataSize; j++) {
        randomNum = rand() % dataSize + 1;
        data[j] = randomNum;
    }
    stringstream fileName;
    fileName << dataSize << "-PartialRandomized.csv";
    fileManifest.push_back(fileName.str());
    printToFile(data, dataSize, fileName.str());
}

void Generator::generatePartialUnique(int dataSize) {
    int uniqueVals = dataSize/5;
    int randomNum;
    int uniqueData[uniqueVals];
    srand (time(NULL));
    for (int i = 0; i < uniqueVals; i++) {
        randomNum = rand() % dataSize + 1;
        uniqueData[i] = randomNum;
    }
    int data[dataSize];
    int counter=0;
    for (int i = 1; i <= 5; i++) {
        for (int j = 0; j < uniqueVals; j++) {
            data[counter] = uniqueData[j];
            counter++;
        }
    }
    stringstream fileName;
    fileName << dataSize << "-PartialUniqueValues.csv";
    fileManifest.push_back(fileName.str());
    printToFile(data, dataSize, fileName.str());
}

void Generator::generateLists() {
    int dataSize;
    for (int i = 0; i < 4; i++) {
        dataSize = this->dataSizes[i];
        generateFullyRandom(dataSize);
        generateReverseSortedOrder(dataSize);
        generatePartialUnique(dataSize);
        generatePartialRandomized(dataSize);
    }
    printManifest();
}

void Generator::printToFile(int data[], int dataSize, string fileName) {
    ofstream myFile;
    myFile.open (fileName);
    for (int i = 0; i < dataSize; i++) {
        if (i == dataSize - 1) {
            myFile << data[i];
        } else {
            myFile << data[i] << ",";
        }
    }
    myFile.close();
}

void Generator::printManifest() {
    ofstream myFile;
    myFile.open("fileManifest.txt");
    for (int i = 0; i < fileManifest.size(); i++) {
        myFile << fileManifest[i] << endl;
    }
    myFile.close();
}