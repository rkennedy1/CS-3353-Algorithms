//
// Created by Ryan on 10/1/19.
//

#include "Search.h"

Search::Search() {
    //searchAlgorithm = new myDFS;
    activeSearchLabel = "Depth First Search";

}

void Search::Load(string dirPath) {
    vector<vector<pair<int, int>>> adjMatrix;
    vector<int> inputArray;
    ifstream inputGraph, inputWeights, inputPositions;
    inputGraph.open(dirPath + "/largeGraph.txt");
    inputWeights.open(dirPath + "/largeWeights.txt");
    inputPositions.open(dirPath + "/largePositions.txt");
    string inputLine;

    int size = 1;
    while (!(inputGraph.eof())) {
        size++;
        getline(inputGraph, inputLine);
        stringstream inputStream(inputLine);
        while (inputStream.good()) {
            string substring;
            getline(inputStream, substring, ',');
            inputArray.push_back(stoi(substring));
        }
        adjMatrix.resize(size);
        int inputArrSize = inputArray.size();
        for (int i = 1; i < inputArray.size(); i++) {
            adjMatrix[inputArray[0]].push_back(make_pair(inputArray[i], 0));
        }
        inputArray.clear();
    }
    while (!(inputWeights.eof())) {
        getline(inputWeights, inputLine);
        stringstream inputStream(inputLine);
        while (inputStream.good()) {
            string substring;
            getline(inputStream, substring, ',');
            inputArray.push_back(stoi(substring));
        }
        for (int i = 0; i < adjMatrix[inputArray[0]].size(); i++) {
            if (adjMatrix[inputArray[0]][i] == make_pair(inputArray[1], 0)) {
                adjMatrix[inputArray[0]][i] = make_pair(inputArray[1], inputArray[2]);
                inputArray.clear();
            }
        }
    }
    vector<tuple<int, int, int>> positions(size);
    while (!(inputPositions.eof())) {
        getline(inputPositions, inputLine);
        stringstream inputStream(inputLine);
        while (inputStream.good()) {
            string substring;
            getline(inputStream, substring, ',');
            inputArray.push_back(stoi(substring));
        }
        positions[inputArray[0]] = make_tuple(inputArray[1], inputArray[2], inputArray[3]);
        inputArray.clear();
    }
    inputGraph.close();
    inputWeights.close();
    graph.loadGraphs(adjMatrix, positions);
}

void Search::Select(int searchAlgorithmInput) {
    switch (searchAlgorithmInput) {
        case DFSITER:
            searchAlgorithm = new IterativeDFS;
            activeSearchLabel = "Depth First Search - Iterative";
            break;
        case DFSRECUR:
            searchAlgorithm = new RecursiveDFS;
            activeSearchLabel = "Depth First Search - Recursive";
            break;
        case BFSITER:
            searchAlgorithm = new IterativeBFS;
            activeSearchLabel = "Breadth First Search - Iterative";
            break;
        case BFSRECUR:
            searchAlgorithm = new RecursiveBFS;
            activeSearchLabel = "Breadth First Search - Recursive";
            break;
        case DIJKSTRA:
            searchAlgorithm = new Dijkstra;
            activeSearchLabel = "Dijkstra";
            break;
        case ASTAR:
            searchAlgorithm = new Astar;
    }
}

void Search::LoadManifest(string manifestFile) {
    ifstream inputFile;
    inputFile.open(manifestFile);
    string currentFileName;
    while (!(inputFile.eof())) {
        getline(inputFile, currentFileName);
        fileManifest.push_back(currentFileName);
        numFiles++;
    }
}

void Search::Execute(int start, int end) {
    searchAlgorithm->SearchData(start, end, graph);
}