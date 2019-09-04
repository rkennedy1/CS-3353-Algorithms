//
// Created by Ryan on 9/4/19.
//
#include "generator.h"
#include <cstdlib>
#include <fstream>
#include <time.h>       /* time */


Generator::Generator() {}

void Generator::setParms(int dataCountParm, string fileNameParm) {
    this->dataCount= dataCountParm;
    this->fileName= fileNameParm;
    int dataArray[this->dataCount];
    this->data = dataArray;
}

void Generator::generatorFullyRandom() {
    int randomNum;
    int data[this->dataCount];
    srand (time(NULL));
    for (int i = 0; i < this->dataCount; i++) {
        randomNum = rand() % this->dataCount + 1;
        this->data[i] = randomNum;
    }
    printToFile(data);
}

void Generator::printToFile(int data[]) {
    ofstream myFile;
    myFile.open (this->fileName);
    for (int i = 0; i < this->dataCount; i++) {
        myFile << data[i] << " ";
    }
    myFile.close();`
}
