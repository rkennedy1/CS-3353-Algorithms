#include <iostream>
#include "generator.h"
int main() {
    Generator g;
    g.setParms(100000, "100000-randomized.txt");
    g.generatorFullyRandom();
    return 0;
}