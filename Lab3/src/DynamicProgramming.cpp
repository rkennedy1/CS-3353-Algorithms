//
// Created by Ryan on 11/2/19.
//

#include "DynamicProgramming.h"

void DynamicProgramming::shortestPath(Graph &g) {
    permutationsDone = 0;
    this->g = g;
    npow = (int) pow(2, g.matrix.size());//bit number required to represent all possible sets
    memo.resize(g.matrix.size());
    p.resize(g.matrix.size());
    for (int i = 0; i < g.matrix.size(); i++) {
        memo[i].resize(npow);
        p[i].resize(npow);
        for (int j = 0; j < npow; j++) {
            memo[i][j] = p[i][j] = -1;
        }
    }
    for (int i = 0; i < g.matrix.size(); i++) {
        memo[i][0] = g.matrix[i][0];
    }
    pathDist = tspRecur(0, npow - 2);
    getPath(0, npow - 2);
    finalPath.insert(finalPath.begin(), g.nodes[0]);
    finalPath.push_back(g.nodes[0]);
}

void DynamicProgramming::getPath(int start, int set) {
    if (p[start][set] == -1) return;//reached null set
    int x = p[start][set];
    int mask = (npow - 1) - (1 << x);
    int masked = set & mask;//remove p from set
    finalPath.push_back(x + 1);
    getPath(x, masked);
}

float DynamicProgramming::tspRecur(int start, int set) {
    float result = 999999999, temp;
    int mask, masked;
    if (memo[start][set] != -1)//checks for repeated subproblem
        return memo[start][set];
    for (int i = 1; i < g.nodes.size(); i++) {
        permutationsDone++;
        mask = (npow - 1) - (1 << i);
        masked = set & mask;
        if (masked != set) {
            temp = g.matrix[start][i] + tspRecur(i, masked);
            if (temp < result) {
                result = temp;
                p[start][set] = i;
            }
        }
    }
    return memo[start][set] = result;
}