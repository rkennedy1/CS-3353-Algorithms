//
// Created by Ryan on 10/1/19.
//

#include "Search.h"

Search::Search() {
    //searchAlgorithm = new myDFS;
    activeSearchLabel = "Depth First Search";

}

void Search::Load(string dirPath) {
    this->dirPath = dirPath;
    vector<vector<pair<int, double>>> adjMatrix;
    vector<int> inputArray;
    vector<double> inputDoubleArray;
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
            if (!substring.empty())
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
            if (!substring.empty())
                inputDoubleArray.push_back(stod(substring));
        }
        for (int i = 0; i < adjMatrix[inputDoubleArray[0]].size(); i++) {
            if (adjMatrix[(int) round(inputDoubleArray[0])][i] == make_pair((int) round(inputDoubleArray[1]), 0.0)) {
                adjMatrix[(int) round(inputDoubleArray[0])][i] = make_pair(inputDoubleArray[1], inputDoubleArray[2]);
                inputDoubleArray.clear();
            }
        }
    }
    vector<tuple<double, double, double>> positions(size);
    while (!(inputPositions.eof())) {
        getline(inputPositions, inputLine);
        stringstream inputStream(inputLine);
        while (inputStream.good()) {
            string substring;
            getline(inputStream, substring, ',');
            if (!substring.empty())
                inputDoubleArray.push_back(stod(substring));
        }
        positions[(int) round(inputDoubleArray[0])] = make_tuple(inputDoubleArray[1], inputDoubleArray[2],
                                                                 inputDoubleArray[3]);
        inputDoubleArray.clear();
    }
    inputGraph.close();
    inputWeights.close();
    inputPositions.close();
    graph.loadGraphs(adjMatrix, positions);
    this->numNodes = size;
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
            activeSearchLabel = "Astar";
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
    this->searchAlgorithm->startTime = chrono::high_resolution_clock::now();
    searchAlgorithm->SearchDataList(start, end, graph);
    this->searchAlgorithm->endTime = chrono::high_resolution_clock::now();
    outputStats("List");
    Stats("List");
    this->searchAlgorithm->startTime = chrono::high_resolution_clock::now();
    searchAlgorithm->SearchDataMatrix(start, end, graph);
    this->searchAlgorithm->endTime = chrono::high_resolution_clock::now();
    Stats("Matrix");
    outputStats("Matrix");
}

void Search::Stats(string type) {
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(
            this->searchAlgorithm->endTime - this->searchAlgorithm->startTime).count();
    time_taken *= 1e-9;
    cout << "Time taken to search from " << start << " to " << end << " using " << activeSearchLabel << " in a "
         << type
         << " is " << fixed << time_taken << setprecision(9) << " sec" << endl;
    cout << "The path found is ";
    for (int i = 0; i < this->searchAlgorithm->finalPath.size(); i++) {
        cout << this->searchAlgorithm->finalPath[i];
        if (i < this->searchAlgorithm->finalPath.size() - 1) {
            cout << "->";
        }
    }
    cout << endl;
    cout << "The number of nodes in the path is " << this->searchAlgorithm->finalPath.size() << endl;
    if (this->searchAlgorithm->finalCost > 0)
        cout << "The cost of the path is " << this->searchAlgorithm->finalCost << endl;
    cout << "The distance of the path is " << this->searchAlgorithm->finalDistance << endl;
    cout << "Number of nodes explored is " << this->searchAlgorithm->numNodesExplored << endl;
    cout << endl;
}

void Search::outputStats(string dataType) {
    ofstream output;
    output.open(dirPath + "/output" + dataType + ".csv", fstream::app);
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(
            this->searchAlgorithm->endTime - this->searchAlgorithm->startTime).count();
    time_taken *= 1e-9;
    output << this->activeSearchLabel << ',' << start << ',' << end << ',' << this->searchAlgorithm->finalPath.size()
           << ','
           << this->searchAlgorithm->numNodesExplored << ',' << fixed << time_taken << setprecision(9) << ','
           << this->searchAlgorithm->finalDistance << ',' << this->searchAlgorithm->finalCost << endl;
    output.close();
}

int Search::generateRandomNode() {
    srand(time(NULL));
    return rand() % numNodes + 1;
}