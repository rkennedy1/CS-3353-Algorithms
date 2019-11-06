#include "Naive.h"
#include "Graph.h"
#include "DynamicProgramming.h"

using namespace std;
int main() {
    Graph g;
    //g.addNode(0, 2.5293, 4.0568, 3.6917);
    g.addNode(1, 12.5293, 14.0568, 13.6917);
    g.addNode(2, 15.1374, 0.752137, 11.0232);
    g.addNode(3, 17.9035, 17.0537, 11.7149);
    g.addNode(4, 6.96459, 6.76679, 10.8797);
    //g.addNode(5, 17.4341, 2.77717, 16.7161);
    //g.addNode(6, 0.003663, 19.7515, 6.93223);
    //g.addNode(7, 10.3523, 2.55067, 16.4621);
    //g.addNode(8, 19.5684, 16.6899, 13.2228);
    //g.addNode(9, 8.27167, 14.1197, 18.7338);
    //g.addNode(10, 2.99695, 12.2009, 19.6331);
    //g.addNode(11, 19.0995, 4.82479, 17.0433);

    Naive n;
    DynamicProgramming dp;
    n.shortestPath(g);
    dp.shortestPath(g);
    return 0;
}