
#include "Search.h"
#include "Algorithm.h"

using namespace std;

int main(int argc, char *argv[]) {
    Search s;
    s.LoadManifest("fileManifest.txt");
    s.start = stoi(argv[1]);
    s.end = stoi(argv[2]);
    for (int i = s.DFSITER; i < s.LAST; i++) {
        for (int j = 0; j < s.fileManifest.size(); j++) {
            s.Load(s.fileManifest[i]);
            s.Select(i);
            s.Execute();
        }
    }
    return 0;
}
