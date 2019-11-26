#include "TSPAlgo.h"

using namespace std;
int main() {
    Algo *A;
    TSPAlgo tsp;
    A = &tsp;
    A->Load("nodes.txt");
    for (int i = tsp.dynamicProgramming; i < tsp.LAST; i++) {
        A->Select(i);
        A->Execute();
    }
    return 0;
}