//
// Created by Ryan on 11/2/19.
//

#include "TSPAlgo.h"

void TSPAlgo::Load(string fileName) {
    g.nodes.clear();
    g.positions.clear();
    g.matrix.clear();
    g.size = 0;
    ifstream inputGraph;
    inputGraph.open(fileName);
    string inputLine;
    vector<float> tempLine;
    while (!(inputGraph.eof())) {
        getline(inputGraph, inputLine);
        stringstream inputStream(inputLine);
        while (inputStream.good()) {
            string substring;
            getline(inputStream, substring, ',');
            if (!substring.empty())
                tempLine.push_back(stof(substring));
        }
        if (!tempLine.empty())
            g.addNode(tempLine[0], tempLine[1], tempLine[2], tempLine[3]);
        tempLine.clear();
    }
    g.createMatrix();
}

void TSPAlgo::Select(int Algo) {
    switch (Algo) {
        case bruteForce:
            tsp = new Naive;
            activeAlgoLabel = "brute force";
            break;
        case dynamicProgramming:
            tsp = new DynamicProgramming;
            activeAlgoLabel = "dynamic programming";
            break;
    }
}

void TSPAlgo::Execute() {
    startTime = chrono::high_resolution_clock::now();
    tsp->shortestPath(g);
    endTime = chrono::high_resolution_clock::now();
    Stats();
}

void TSPAlgo::Stats() {
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(endTime - startTime).count();
    time_taken *= 1e-6;
    cout << "Time taken to find optimal path using " << activeAlgoLabel << ": " << time_taken << " milliseconds"
         << endl;
    cout << "Optimal path: ";
    for (int i = 0; i < tsp->finalPath.size(); i++) {
        if (i < tsp->finalPath.size() - 1)
            cout << tsp->finalPath[i] << "->";
        else
            cout << tsp->finalPath[i] << endl << "Path Size:" << tsp->pathDist << endl;
    }
    cout << "Permutations done: " << tsp->permutationsDone << endl << endl;
}