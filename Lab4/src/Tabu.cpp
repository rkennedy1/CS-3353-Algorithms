//
// Created by Ryan on 11/26/19.
//

#include "Tabu.h"

void Tabu::shortestPath(Graph &g) {
    permutationsDone = 0;
    iter = g.size*g.size;
    tabu.clear();
    pair<float, vector<int>> bestSolution = randomPair(g);
    tabu.push_back(bestSolution);
    int i = 0;
    while (i < iter) {
        //swapRandomNeighbors(bestSolution, g); //does not find the optimal solution frequently but would find a short path most of the time
        swapAllNeighbors(bestSolution, g);
        tabu.push_back(bestSolution);
        if (tabu.size() > size)
            tabu.erase(tabu.begin());
        i++;
    }
    pathDist = bestSolution.first;
    finalPath = bestSolution.second;
}

bool Tabu::contains(pair<float, vector<int>> p) {
    for (int i = 0; i < tabu.size(); i++)
        if (p == tabu[i])
            return true;
    return false;
}

pair<float, vector<int>> Tabu::randomPair(Graph &g) {
    pair<float, vector<int>> pair;
    float temp = 0;
    pair.second.push_back(1);
    for (int i = 2; i <= g.size; i++)
        pair.second.push_back(i);
    pair.second.push_back(1);
    shuffle(pair.second.begin() + 1, pair.second.end() - 1, default_random_engine{});
    for (int i = 0; i < pair.second.size() - 1; i++)
        temp += g.getDist(pair.second[i], pair.second[i + 1]);
    pair.first = temp;
    return pair;
}

void Tabu::swapAllNeighbors(pair<float, vector<int>> &p, Graph &g) {
    pair<float, vector<int>> newSolution = p;
    for (int i = 1; i < g.size; i++) {
        for (int j = 1; j < g.size; j++) {
            if (i != j) {
                permutationsDone++;
                swap(i, j, g, newSolution);
                if (newSolution.first < p.first && !contains(newSolution))
                    p = newSolution;
            }
        }
    }
}

void Tabu::swapRandomNeighbors(pair<float, vector<int>> &p, Graph &g) {
    for (int i = 0; i < g.size * g.size; i++) {
        srand(time(NULL));
        int a = rand() % g.size;
        for (int j = 0; j < g.size; j++) {
            permutationsDone++;
            pair<float, vector<int>> newSolution = p;
            srand(time(NULL));
            int b = rand() % g.size;
            swap(a, b, g, newSolution);
            if (newSolution.first < p.first && !contains(newSolution))
                p = newSolution;
        }
    }
}

void Tabu::swap(int a, int b, Graph &g, pair<float, vector<int>> &p) {
    float temp = p.second[a];
    p.second[a] = p.second[b];
    p.second[b] = temp;
    temp = 0;
    for (int i = 0; i < p.second.size() - 1; i++) {
        temp += g.getDist(p.second[i], p.second[i + 1]);
    }
    p.first = temp;
}