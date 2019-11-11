#include "TSPAlgo.h"

using namespace std;
int main() {
    Algo *A;
    TSPAlgo tsp;
    A = &tsp;
    //for (int i = 4; i <= 12; i++) { //This loop is for testing multiple files of different sizes
    //A->Load(to_string(i) + "Nodes.txt");
    A->Load("11Nodes.txt");
    for (int i = tsp.dynamicProgramming; i < tsp.LAST; i++) {
            A->Select(i);
            A->Execute();
        }
    //}
    return 0;
}