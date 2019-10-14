//
// Created by Ryan on 10/13/19.
//

#ifndef LAB2_SEARCHALGORITHM_H
#define LAB2_SEARCHALGORITHM_H

#include <vector>
#include "Graph.h"

using namespace std;

class SearchAlgorithm {
public:
    virtual void SearchData(int source, int target, Graph g) = 0;
};

#endif //LAB2_SEARCHALGORITHM_H
