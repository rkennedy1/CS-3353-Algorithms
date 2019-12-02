#include "TSPAlgo.h"

using namespace std;

int LoadManifest(string manifestFile, vector<string>& fileManifest) {
    int numFiles = 0;
    ifstream inputFile;
    inputFile.open(manifestFile);
    string currentFileName;
    while (!(inputFile.eof())) {
        getline(inputFile, currentFileName);
        fileManifest.push_back(currentFileName);
        numFiles++;
    }
    return numFiles;
}

int main() {
    Algo *A;
    TSPAlgo tsp;
    A = &tsp;
    vector<string> fileManifest;
    int numFiles = LoadManifest("fileManifest.txt", fileManifest);
    for (int j = 0; j < numFiles-1; j++) {
        A->Load(fileManifest[j]);
        for (int i = tsp.dynamicProgramming; i < tsp.LAST; i++) {
            for (int j = 0; j < 10; j++) {
                A->Select(i);
                A->Execute();
            }
        }
    }
    return 0;
}

