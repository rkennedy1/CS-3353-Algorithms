//
// Created by Ryan on 9/8/19.
//

#include "Sort.h"
#include <fstream>
#include <iostream>

Sort::Sort() {

}

void Algorithm::Load(string fileName) {
    size_t pos = fileName.find("-");
    string dataSizeStr = fileName.substr(0, pos);
    int dataSize = stoi(dataSizeStr);
    ofstream myFile;
    myFile.open(fileName);
    int data[dataSize];
    for (int i = 0; i < dataSize; i++) {

    }
}