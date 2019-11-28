//
// Created by Ryan on 11/26/19.
//

#include "Tabu.h"

void Tabu::shortestPath(Graph &g) {
    permutationsDone = 0;
    list.clear();
    pair<float, vector<int>> bestSolution = init(g);
    list.push_back(bestSolution);
    int i = 0;
    while (i < iterNum) {
        bestSolution = findNeighbor(bestSolution, g);
        list.push_back(bestSolution);
        if (list.size() > size)
            list.erase(list.begin());
        i++;
    }
    pathDist = bestSolution.first;
    finalPath = bestSolution.second;
}

bool Tabu::contains(pair<float, vector<int>> s) {
    for (int i = 0; i < list.size(); i++) {
        if (s == list[i])
            return true;
    }
    return false;
}

pair<float, vector<int>> Tabu::init(Graph &g) {
    pair<float, vector<int>> pair;
    float temp = 0;
    long seed = chrono::system_clock::now().time_since_epoch().count();
    for (int i = 2; i <= g.size; i++)
        pair.second.push_back(i);
    shuffle(pair.second.begin(), pair.second.end(), default_random_engine(seed));
    pair.second.push_back(1);
    pair.second.insert(pair.second.begin(), 1);
    for (int i = 0; i < pair.second.size() - 1; i++)
        temp += g.getDist(pair.second[i], pair.second[i + 1]);
    pair.first = temp;
    return pair;
}

pair<float, vector<int>> Tabu::findNeighbor(pair<float, vector<int>> s, Graph &g) {
    pair<float, vector<int>> newSolution = s;
    for (int i = 1; i < g.size; i++) {
        for (int j = 1; j < g.size; j++) {
            swap(i, j, g, newSolution);
            permutationsDone++;
            if (newSolution.first < s.first && !contains(newSolution))
                s = newSolution;
        }
    }
    return s;
}

void Tabu::swap(int a, int b, Graph &g, pair<float, vector<int>> &p) {
    int temp = p.second[a];
    p.second[a] = p.second[b];
    p.second[b] = temp;
    temp = 0;
    for (int i = 0; i < p.second.size() - 1; i++) {
        temp += g.getDist(p.second[i], p.second[i + 1]);
    }
    p.first = temp;
}