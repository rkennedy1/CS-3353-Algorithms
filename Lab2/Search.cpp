//
// Created by Ryan on 10/1/19.
//

#include "Search.h"

Search::Search() {
    //searchAlgorithm = new myDFS;
    activeSearchLabel = "Depth First Search";

}

void Search::Load(string dirPath) {
    vector<vector<int>> adjMatrix;
    vector<int> inputArray;
    ifstream inputFile;
    inputFile.open(dirPath + "/largeGraph.txt");
    string inputLine;
    int size;
    while (!(inputFile.eof())) {
        size++;
        getline(inputFile, inputLine);
        stringstream inputStream(inputLine);
        while (inputStream.good()) {
            string substring;
            getline(inputStream, substring, ',');
            inputArray.push_back(stoi(substring));
        }
        adjMatrix.resize(size);
        for (int i = 1; i < inputArray.size(); i++) {
            adjMatrix[inputArray[0]].push_back(inputArray[i]);
        }
        inputArray.clear();
    }
    graph.loadGraphs(adjMatrix);
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

void Search::Execute() {
    searchAlgorithm->SearchData(2, 8, graph);
}