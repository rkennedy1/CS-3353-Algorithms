//
// Created by Ryan on 10/12/19.
//
#include "Dijkstra.h"

void Dijkstra::DijkstraList(int start, int target) {
    vector<double> distance;
    vector<int> path;
    pair<vector<int>, int> finalPath;
    finalPath.second = INT_MAX;
    int tempDistance = 0;

    for (int i = 0; i < this->g.adjList.size(); i++) {
        distance.push_back(INT_MAX); //makes all distances 'infinity'
    }
    priority_queue<tuple<int, int, vector<int>>, vector<tuple<int, int, vector<int>>>, greater<tuple<int, int, vector<int>>>> priorityQueue;
    path.push_back(start);
    priorityQueue.push(make_tuple(start, 0, path));
    distance[start] = 0;

    while (!priorityQueue.empty()) {
        // Get min distance vertex from priorityQueue. (Call it parent.)
        int parent = get<0>(priorityQueue.top());
        path = get<2>(priorityQueue.top());
        tempDistance = get<1>(priorityQueue.top());
        priorityQueue.pop();
        this->numNodesExplored++;

        int lastNode = path[path.size() - 1];
        if (lastNode == target) {
            if (finalPath.second > tempDistance) {
                finalPath.first = path;
                finalPath.second = tempDistance;
            }
        }
        // Visit all of parent's friends. For each one (called v)....
        for (int i = 0; i < this->g.adjList[parent].size(); i++) {
            int child = this->g.adjList[parent][i].first;
            double weight = this->g.adjList[parent][i].second;

            if (distance[child] > distance[parent] + weight) {
                distance[child] = distance[parent] + weight;
                vector<int> newPath(path);
                newPath.push_back(child);
                priorityQueue.push(make_tuple(child, distance[child], newPath));
            }
        }
    }
    this->finalPath = finalPath.first;
    this->finalDistance = distance[target];
    this->finalCost = -1;
}

void Dijkstra::DijkstraMatrix(int start, int target) {
    vector<double> distance;
    vector<int> path;
    pair<vector<int>, int> finalPath;
    finalPath.second = INT_MAX;
    int tempDistance = 0;

    for (int i = 0; i < this->g.adjMatrix.size(); i++) {
        distance.push_back(INT_MAX); //makes all distances 'infinity'
    }
    priority_queue<tuple<int, int, vector<int>>, vector<tuple<int, int, vector<int>>>, greater<tuple<int, int, vector<int>>>> priorityQueue;
    path.push_back(start);
    priorityQueue.push(make_tuple(start, 0, path));
    distance[start] = 0;

    while (!priorityQueue.empty()) {
        // Get min distance vertex from priorityQueue. (Call it parent.)
        int parent = get<0>(priorityQueue.top());
        path = get<2>(priorityQueue.top());
        tempDistance = get<1>(priorityQueue.top());
        priorityQueue.pop();
        this->numNodesExplored++;

        int lastNode = path[path.size() - 1];
        if (lastNode == target) {
            if (finalPath.second > tempDistance) {
                finalPath.first = path;
                finalPath.second = tempDistance;
            }
        }
        // Visit all of parent's friends. For each one (called v)....
        for (int i = 0; i < this->g.adjMatrix[parent].size(); i++) {
            if (this->g.adjMatrix[lastNode][i].first == 1) {
                int child = i;
                double weight = this->g.adjMatrix[parent][i].second;

                if (distance[child] > distance[parent] + weight) {
                    distance[child] = distance[parent] + weight;
                    vector<int> newPath(path);
                    newPath.push_back(child);
                    priorityQueue.push(make_tuple(child, distance[child], newPath));
                }
            }
        }
    }
    this->finalPath = finalPath.first;
    this->finalDistance = distance[target];
    this->finalCost = -1;
}

void Dijkstra::SearchDataList(int source, int target, Graph g) {
    this->numNodesExplored = 0;
    this->g = g;
    DijkstraList(source, target);
}

void Dijkstra::SearchDataMatrix(int source, int target, Graph g) {
    this->numNodesExplored = 0;
    this->g = g;
    DijkstraMatrix(source, target);
}