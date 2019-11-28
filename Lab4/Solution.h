//
// Created by Ryan on 11/26/19.
//

#ifndef LAB4_SOLUTION_H
#define LAB4_SOLUTION_H

#include "Graph.h"
#include <vector>
#include <random>
#include <chrono>


using namespace std;

class Solution {
public:
    vector<int> path;
    float score;

    Solution(Graph &);

    bool operator==(const Solution &);

    void swapSolution(int, int, Graph &);
};


#endif //LAB4_SOLUTION_H
