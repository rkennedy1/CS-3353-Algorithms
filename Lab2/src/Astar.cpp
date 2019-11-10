w//
// Created by Ryan on 10/15/19.
//

#include "Astar.h"

void Astar::AstarList(int start, int target) {
    vector<double> adjDistance;
    vector<double> trueDistance;
    vector<int> path;
    vector<pair<vector<int>, int>> paths;
    double tempDistance = 0;

    for (int i = 0; i < this->g.adjList.size(); i++) {
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
            return;
        }
        for (int i = 0; i < this->g.adjList[parent].size(); i++) {
            int child = this->g.adjList[parent][i].first;
            double childWeight = this->g.adjList[parent][i].second;
            double childHeuristic = findDistance(this->g.positions[child], this->g.positions[target]);
            double adjChildWeight = childWeight + childHeuristic;

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

void Astar::AstarMatrix(int start, int target) {
    vector<double> adjDistance;
    vector<double> trueDistance;
    vector<int> path;
    vector<pair<vector<int>, int>> paths;
    double tempDistance = 0;

    for (int i = 0; i < this->g.adjMatrix.size(); i++) {
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
            return;
        }
        for (int i = 0; i < this->g.adjMatrix[parent].size(); i++) {
            if (this->g.adjMatrix[lastNode][i].first == 1) {
                int child = i;
                double childWeight = this->g.adjMatrix[parent][i].second;
                double childHeuristic = findDistance(this->g.positions[child], this->g.positions[target]);
                double adjChildWeight = childWeight + childHeuristic;

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

}


double Astar::findDistance(tuple<double, double, double> a, tuple<double, double, double> b) {
    return (pow((get<0>(b) - get<0>(a)), 2)
            + (pow((get<1>(b) - get<1>(a)), 2))
            + pow((get<2>(b) - get<2>(a)), 2));
}

void Astar::SearchDataList(int source, int target, Graph g) {
    this->numNodesExplored = 0;
    this->g = g;
    AstarList(source, target);
}

void Astar::SearchDataMatrix(int source, int target, Graph g) {
    this->numNodesExplored = 0;
    this->g = g;
    AstarMatrix(source, target);
}