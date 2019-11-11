#include "TSPAlgo.h"

using namespace std;
int main() {
    Algo *A;
    TSPAlgo tsp;
    A = &tsp;
    for (int i = 4; i <= 12; i++) {
        A->Load(to_string(i) + "Nodes.txt");
        for (int i = tsp.dynamicProgramming; i < tsp.bruteForce; i++) {
            A->Select(i);
            A->Execute();
        }
    }
    return 0;
}

/*
    g.addNode(1, 55, 50, 4);
    g.addNode(2, 100, 140, 180);
    g.addNode(3, 30, 30, 30);
    g.addNode(4, 200, 200, 200);
    g.addNode(5, 100, 100, 100);
    g.addNode(6, 10, 10, 10);
    g.addNode(7, 10.3523, 2.55067, 16.4621);
    g.addNode(8, 19.5684, 16.6899, 13.2228);
    g.addNode(9, 8.27167, 14.1197, 18.7338);
    g.addNode(10, 2.99695, 12.2009, 19.6331);
    g.addNode(11, 19.0995, 4.82479, 17.0433);
    g.addNode(12, 10.0995, 14.82479, 27.0433);
*/