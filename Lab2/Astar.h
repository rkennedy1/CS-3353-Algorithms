//
// Created by Ryan on 10/15/19.
//

#ifndef LAB2_ASTAR_H
#define LAB2_ASTAR_H

#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include "SearchAlgorithm.h"

using namespace std;

class Astar : public SearchAlgorithm {
private:
    Graph g;

    void AstarList(int start, int target);

    void AstarMatrix(int start, int target);

    double findDistance(tuple<double, double, double> a, tuple<double, double, double> b);
public:
    void SearchDataList(int source, int target, Graph g);

    void SearchDataMatrix(int source, int target, Graph g);
};


#endif //LAB2_ASTAR_H
