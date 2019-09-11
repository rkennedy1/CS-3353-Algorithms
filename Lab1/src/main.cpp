#include <iostream>
#include "generator.h"
#include "Sort.h"
#include "Algorithm.h"
#include "Merge.h"
#include "Insertion.h"
#include <fstream>

int main() {

    Algorithm *A;
    Sort s;
    A = &s;
    s.LoadManifest("fileManifest.txt");
    for (int i = s.INSERTION; i < s.LAST; i++) {
        for (int j = 0; j < s.numFiles-1; j++) {
            A->Select(i);
            A->Load(s.fileManifest[j]);
            A->Execute();
            A->Save(s.fileManifest[j]);
            //A->Display();
            A->Stats();
        }
    }

    /* this is how I run my generator.
     * To run the data generator comment everything else out
     * except this the next two lines */
     // Generator g;
     // g.generateLists();

    return 0;
}