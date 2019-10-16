//
// Created by Ryan on 10/15/19.
//

#include "Astar.h"

void Astar::AstarPath(vector<vector<pair<int, int>>> &graph, vector<tuple<int, int, int>> &positions, int &start,
                      int target) {
    vector<int> adjDistance;
    vector<int> trueDistance;
    vector<int> path;
    vector<pair<vector<int>, int>> paths;
    int tempDistance = 0;

    for (int i = 0; i < graph.size(); i++) {
        adjDistance.push_back(INT_MAX); //makes all distances 'infinity'
        trueDistance.push_back(INT_MAX);
    }
    priority_queue<tuple<int, int, vector<int>>, vector<tuple<int, int, vector<int>>>, greater<tuple<int, int, vector<int>>>> priorityQueue;
    path.push_back(start);
    priorityQueue.push(make_tuple(start, 0, path));
    adjDistance[start] = 0;
    trueDistance[start] = 0;

    while (!priorityQueue.empty()) {
        int parent = get<0>(priorityQueue.top());
        path = get<2>(priorityQueue.top());
        tempDistance = get<1>(priorityQueue.top());
        priorityQueue.pop();
        this->numNodesExplored++;

        int lastNode = path[path.size() - 1];
        if (lastNode == target) {
            this->finalPath = path;
            this->finalDistance = trueDistance[target];
            this->finalCost = tempDistance;
        }
        for (int i = 0; i < graph[parent].size(); i++) {
            int child = graph[parent][i].first;
            int childWeight = graph[parent][i].second;
            int childHeuristic = findDistance(positions[child], positions[target]);
            int adjChildWeight = childWeight + childHeuristic;

            if (adjDistance[child] > adjDistance[parent] + adjChildWeight) {
                adjDistance[child] = adjDistance[parent] + adjChildWeight;
                trueDistance[child] = trueDistance[parent] + childWeight;
                vector<int> newPath(path);
                newPath.push_back(child);
                priorityQueue.push(make_tuple(child, adjDistance[child], newPath));
            }
        }
    }

}

int Astar::findDistance(tuple<int, int, int> a, tuple<int, int, int> b) {
    return (pow((get<0>(b) - get<0>(a)), 2)
            + (pow((get<1>(b) - get<1>(a)), 2))
            + pow((get<2>(b) - get<2>(a)), 2));
}

void Astar::printShortestPath(vector<int> adjDistance, int start) {
    for (int j = start; j < adjDistance.size(); j++) {
        cout << "Distance from " << start << " to " << j << " is " << adjDistance[j] << endl;
    }
}

void Astar::printShortestPath(vector<pair<vector<int>, int>> paths) {
    for (int j = 0; j < paths.size(); j++) {
        for (int i = 0; i < paths[j].first.size(); i++) {
            cout << paths[j].first[i] << " ";
        }
        cout << " - Astar Distance: " << paths[j].second << endl;
    }
}

void Astar::SearchData(int source, int target, Graph g) {
    this->numNodesExplored = 0;
    AstarPath(g.adjMatrix, g.positions, source, target);
}