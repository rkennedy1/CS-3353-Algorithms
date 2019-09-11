#include <iostream>
#include "generator.h"
#include "Sort.h"
#include "Algorithm.h"
#include "Merge.h"
#include "Insertion.h"
#include <fstream>

vector<string> fileManifest;
void LoadManifest(string manifestFile);

int main() {
    Algorithm *A;
    Sort s;
    A = &s;
    LoadManifest("dataSetFileNames.txt");
    for (int i = 1; i < 4; i++) {
        for (int j = 0; j < 16; j++) {
            A->Select(i);
            A->Load(fileManifest[j]);
            A->Execute();
            A->Save(fileManifest[j]+"-"+to_string(i)+"-Solved.txt");
            //A->Display();
            A->Stats();
        }
    }
    /*Generator g; //this is how I run my generator. To run the data generator comment everything else out except this line and the next line
    g.generateLists();*/
    return 0;
}

void LoadManifest(string manifestFile) {
    ifstream inputFile;
    inputFile.open(manifestFile);
    string currentFileName;
    while (!(inputFile.eof())) {
        getline(inputFile, currentFileName);
        fileManifest.push_back(currentFileName);
    }
}
