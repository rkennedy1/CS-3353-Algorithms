#include <iostream>
#include "generator.h"
#include "Sort.h"
#include "Algorithm.h"
#include "Merge.h"
#include "Insertion.h"
int main() {
    Algorithm *A;
    Sort *s;
    Merge m;
    s = &m;
    A = s;
    A->Load("dataSetFileNames.txt");
    /*Generator g; //this is how I run my generator. To run the data generator comment everything else out except this line and the next line
    g.generateLists();*/
    return 0;
}