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
    int dataSizes[4] = {10, 1000, 10000, 100000};
    void generateFullyRandom(int dataSize);
    void generateReverseSortedOrder(int dataSize);
    void generatePartialRandomized(int dataSize);
    void generatePartialUnique(int dataSize);
    void printToFile(int data[], int dataSize, string fileName);
    void print(int data[], int dataSize);
public:
    Generator();
    void generateLists();
};