//
// Created by Ryan on 11/2/19.
//

#ifndef LAB3_NAIVE_H
#define LAB3_NAIVE_H

#include <vector>
#include <tuple>

using namespace std;

class Naive {
private:
    int nodeExplored;
    vector<tuple<float, float,float>> bestPath;
    int calcDistance(tuple<float,float,float> a, tuple<float,float,float> b);
public:
    vector<int> shortestPath(vector<vector<tuple<float,float,float>>> points);
};


#endif //LAB3_NAIVE_H
