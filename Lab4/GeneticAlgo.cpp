//
// Created by Ryan on 12/1/19.
//

#include "GeneticAlgo.h"

void GeneticAlgo::shortestPath(Graph &g) {
    introPop(g);
    for (int i = 0; i < numGenerations; i++) {
        chooseParents(RANDOM);
        crossover(g);
    }
    int index = 0;
    float minDist = MAXFLOAT;
    for (int i = 0; i < population.size(); i++) {
        if (population[i].first < minDist) {
            minDist = population[i].first;
            index = i;
        }
    }
    finalPath = population[index].second;
    pathDist = population[index].first;
}

void GeneticAlgo::introPop(Graph &g) {
    parents.first = 0;
    parents.second = 0;
    for (int i = 0; i < popSize; i++)
        population.push_back(randomPair(g));
}

pair<float, vector<int>> GeneticAlgo::randomPair(Graph &g) {
    pair<float, vector<int>> newPair;
    newPair.second.push_back(1);
    for (int i = 1; i < g.size; i++)
        newPair.second.push_back(g.nodes[i]);
    newPair.second.push_back(1);
    default_random_engine engine;
    engine.seed(std::chrono::system_clock::now().time_since_epoch().count());
    shuffle(newPair.second.begin() + 1, newPair.second.end() - 1, engine);
    newPair.first = g.getPathDistance(newPair.second);
    return newPair;
}

void GeneticAlgo::chooseParents(int type) {
    if (type == RANDOM) {
        srand(time(NULL));
        parents.first = rand() % (popSize - 1);
        parents.second = rand() % (popSize - 1);
    } else if (type == ELITE) {
        float bestDist = MAXFLOAT;
        int a = 0, b = 0;
        for (int i = 0; i < popSize; i++) {
            if (population[i].first < bestDist) {
                b = a;
                a = i;
                bestDist = population[i].first;
            }
        }
        parents.first = a;
        parents.second = b;
    } else if (type == ROULETTE) {
        vector<float> adjPopFitness;
        float totalFitness = 0;
        for (int i = 0; i < popSize; i++)
            totalFitness += population[i].first;
        for (int i = 0; i < popSize; i++)
            adjPopFitness.push_back(population[i].first/totalFitness);
        double rand1 = rand();
        double rand2 = rand();
        float fitness = 0;
        for (int i = 0; i < adjPopFitness.size(); i++) {
            fitness += adjPopFitness[i];
            if (rand1 < fitness && parents.first == 0) {
                parents.first = i;
            } else if (rand2 < fitness && parents.second == 0) {
                parents.second = i;
            }
        }
    }
}

void GeneticAlgo::crossover(Graph &g) {
    vector<int> parentAPath = population[parents.first].second;
    vector<int> parentBPath = population[parents.second].second;
    pair<float, vector<int>> offspringA, offspringB;
    srand(time(NULL));
    int cutoff = rand() % (parentAPath.size() - 1);
    for (int i = 0; i < parentAPath.size(); i++) {
        if (i < cutoff) {
            offspringA.second.push_back(parentAPath[i]);
            offspringB.second.push_back(parentBPath[i]);
        } else {
            offspringA.second.push_back(parentBPath[i]);
            offspringB.second.push_back(parentAPath[i]);
        }
    }
    int mut = rand() % 100;
    if (mut < mutRate) {
        int chance = rand() % 2 + 1;
        if (chance == 1) {
            mutate(offspringA, g);
        } else {
            mutate(offspringB, g);
        }
    }
    offspringA.first = g.getPathDistance(offspringA.second);
    offspringB.first = g.getPathDistance(offspringB.second);
}

void GeneticAlgo::mutate(pair<float, vector<int>> &p, Graph &g) {
    srand(time(NULL));
    int mut1 = rand() % (p.second.size() - 1);
    int mut2 = rand() % (p.second.size() - 1);
    swap(mut1, mut2, g, p);
}

void GeneticAlgo::swap(int a, int b, Graph &g, pair<float, vector<int>> &p) {
    float temp = p.second[a];
    p.second[a] = p.second[b];
    p.second[b] = temp;
    p.first = g.getPathDistance(p.second);
}