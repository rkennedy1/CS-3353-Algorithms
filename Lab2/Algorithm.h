//
// Created by Ryan on 10/1/19.
//

#ifndef LAB2_ALGORITHM_H
#define LAB2_ALGORITHM_H

#endif //LAB2_ALGORITHM_H

#include <string>

using namespace std;

class Algorithm {
public:
    virtual void Load(string fileName) = 0;
    virtual void Execute() = 0;
    virtual void Display() = 0;
    virtual void Stats() = 0;
    virtual void Select(int sortAlgo) = 0;
    virtual void Save(string filePath) = 0;
    virtual void Configure() = 0;
};