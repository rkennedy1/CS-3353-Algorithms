//
// Created by Ryan on 11/2/19.
//

#include "Naive.h"


vector<int> Naive::shortestPath(vector<vector<tuple<float,float,float>>> points) {
    vector<int> vertex;
    int s = 0;
    for (int i = 0; i < points.size(); i++) {
        if (i != s) {
            vertex.push_back(i);
        }
    }
    int minPath = INT_MAX;
    vector<int> bestPath;
    do {
        int currentWeight = 0;
        vector<int> currentPath;
        int k = s;
        for (int i = 1; i < points.size(); i++) {
            currentWeight += calcDistance(points[k][vertex[i]], points[k-1][vertex[i-1]]);
            currentPath.push_back(vertex[i]);
            k = vertex[i];
        }
        currentWeight += calcDistance(points[k][s], points[k+1][s+1]);
        if (currentWeight < minPath) {
            minPath = currentWeight;
            bestPath = currentPath;
        }
        minPath = min(minPath, currentWeight);
    } while(next_permutation(vertex.begin(), vertex.end()));
    return bestPath;
}

int Naive::calcDistance(tuple<float, float, float> a, tuple<float, float, float> b) {
    return (get<0>(a) - get<0>(b)) + (get<1>(a) - get<1>(b)) + (get<2>(a) - get<2>(b));
}