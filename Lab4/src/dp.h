//
// Created by Ryan on 11/2/19.
//

#ifndef LAB3_DYNAMICPROGRAMMING_H
#define LAB3_DYNAMICPROGRAMMING_H

#include "TSP.h"

using namespace std;

class dp: public TSP {
private:
    Graph g;
    vector<vector<float>> memo;
    vector<vector<int>> p;
    int npow;

    void getPath(int start, int set);
    float tspRecur(int start, int set);
public:
    void shortestPath(Graph &g);
};


#endif //LAB3_DYNAMICPROGRAMMING_H
