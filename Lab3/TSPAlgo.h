//
// Created by Ryan on 11/2/19.
//

#ifndef LAB3_TSPALGO_H
#define LAB3_TSPALGO_H

#include "Algo.h"
#include <string>
#include "Naive.h"
#include "DynamicProgramming.h"
#include "TSP.h"
#include "Graph.h"
#include <fstream>
#include <sstream>

class TSPAlgo : public Algo {
public:
     void Load(string fileName) ;
     void Execute() ;
     void Display() ;

    void Stats();

    void Select(int Algo);
     void Save(string filePath);
     void Configure();

    enum Algo {
        dynamicProgramming, bruteForce, LAST
    };
    Graph g;
private:
    chrono::steady_clock::time_point startTime;
    chrono::steady_clock::time_point endTime;
    string activeAlgoLabel;
    TSP *tsp;
};


#endif //LAB3_TSPALGO_H
