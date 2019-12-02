//
// Created by Ryan on 12/1/19.
//

#ifndef LAB4_GENETICALGO_H
#define LAB4_GENETICALGO_H

#include "Graph.h"
#include "TSP.h"
#include <random>

class GeneticAlgo : public TSP {
private:
    int popSize = 5000;
    int numGenerations = 1000;
    int mutRate = 20;
    vector<pair<float, vector<int>>> population;
    pair<int, int> parents;
    enum parentType {
        RANDOM, ELITE, ROULETTE
    };

    void introPop(Graph &);

    void swap(int, int, Graph &, pair<float, vector<int>> &);

    void chooseParents(int);

    void crossover(Graph &);

    void mutate(pair<float, vector<int>> &, Graph &);

    pair<float, vector<int>> randomPair(Graph &);

public:
    virtual void shortestPath(Graph &g);
};


#endif //LAB4_GENETICALGO_H
