//
// Created by Ryan on 9/8/19.
//

#ifndef LAB1_ALGORITHM_H
#define LAB1_ALGORITHM_H
#include <string>

using namespace std;

class Algorithm {
private:

public:
    virtual void Load(string fileName) = 0;
    virtual void Execute() = 0;
    virtual void Display() = 0;
    virtual void Stats() = 0;
    virtual void Select(int sortAlgo) = 0;
    virtual void Save(string filePath) = 0;
    virtual void Configure() = 0;
};


#endif //LAB1_ALGORITHM_H
