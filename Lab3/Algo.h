//
// Created by Ryan on 11/2/19.
//

#ifndef LAB3_ALGO_H
#define LAB3_ALGO_H

#include <string>

using namespace std;

class Algo {
public:
    //  virtual void Load(string fileName) = 0;
    virtual void Execute() = 0;
    //  virtual void Display() = 0;

    virtual void Stats() = 0;
    virtual void Select(int sortAlgo) = 0;
    //   virtual void Save(string filePath) = 0;
    //  virtual void Configure() = 0;
};

#endif //LAB3_ALGO_H
