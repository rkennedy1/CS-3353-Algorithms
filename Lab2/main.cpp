
#include "Search.h"
#include "Algorithm.h"

using namespace std;

int main(int argc, char *argv[]) {
    Search s;
    s.LoadManifest("fileManifest.txt");
    s.start = stoi(argv[1]);
    s.end = stoi(argv[2]);
    s.Load(s.fileManifest[0]);
    vector<int> inputStart;
    vector<int> inputEnd;
    for (int j = 0; j < 100; j++) {
        inputStart.push_back(s.generateRandomNode());
        inputEnd.push_back(s.generateRandomNode());
        while (inputStart[j] == inputEnd[j]) {
            inputEnd[j] = s.generateRandomNode();
        }
        if (j > 0) {
            while (inputEnd[j - 1] == inputStart[j]) {
                inputStart[j] = s.generateRandomNode();
                while (inputStart[j] == inputEnd[j]) {
                    inputEnd[j] = s.generateRandomNode();
                }
            }
        }
    }
    for (int i = s.DFSITER; i < s.LAST; i++) {
        s.Select(i);
        for (int j = 0; j < 100; j++) {
            s.start = inputStart[j];
            s.end = inputEnd[j];
            s.Execute();
        }
    }
    return 0;
}
