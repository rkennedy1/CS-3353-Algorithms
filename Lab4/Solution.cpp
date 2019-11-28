//
// Created by Ryan on 11/26/19.
//

#include "Solution.h"

Solution::Solution(Graph &g) {
    long seed = chrono::system_clock::now().time_since_epoch().count();
    for (int i = 2; i <= g.size; i++)
        path.push_back(i);
    shuffle(path.begin(), path.end(), default_random_engine(seed));
    path.push_back(1);
    path.insert(path.begin(), 1);
    score = 0;
    for (int i = 0; i < path.size() - 1; i++) {
        score += g.getDist(path[i], path[i + 1]);
    }
}

bool Solution::operator==(const Solution &rhs) {
    return this->path == rhs.path;
}

void Solution::swapSolution(int a, int b, Graph &g) {
    int temp = path[a];
    path[a] = path[b];
    path[b] = temp;
    score = 0;
    for (int i = 0; i < path.size() - 1; i++) {
        score += g.getDist(path[i], path[i + 1]);
    }
}