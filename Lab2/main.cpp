#include <iostream>
#include "Graph.h"
#include "myDFS.h"

using namespace std;

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);


    cout << endl << "DFS" << endl;
    myDFS d(g);
    d.DFSRecur(0, 3);
    /*cout << endl << "DFS Recursive" << endl;
    d.DFSrecurUtl(2);
    myBFS b(g);
    cout << endl << "BFS" << endl;
    b.BFS(0, 2);*/

    Graph q(4);
    q.addEdge(0, 1);
    q.addEdge(0, 2);
    q.addEdge(1, 2);
    q.addEdge(2, 0);
    q.addEdge(2, 3);
    q.addEdge(3, 3);

    cout << endl << "DFS" << endl;
    myDFS D(q);
    D.DFSRecur(1, 3);
    /* cout << endl << "DFS Recursive" << endl;
     D.DFSrecurUtl(0);
     myBFS B(q);
     cout << endl << "BFS" << endl;
     B.BFS(0, 3);*/
    return 0;
}