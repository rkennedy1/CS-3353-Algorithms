//
// Created by Ryan on 9/4/19.
//

#ifndef LAB1_GENERATOR_H
#define LAB1_GENERATOR_H

#endif //LAB1_GENERATOR_H

#include <string>

using namespace std;

class Generator {
private:
    int dataCount;
    string fileName;
    int* data;
public:
    Generator();
    void generatorFullyRandom();
    void printToFile(int data[]);
    void setParms(int dataCountParm, string fileNameParm);
};