//
// Created by Ryan on 10/12/19.
//
#include "Dijkstra.h"

vector<int> Dijkstra::DijkstraAlgo(vector<vector<pair<int, int>>> &graph, int &start, int target) {
    vector<int> distance;
    vector<int> path;
    vector<pair<vector<int>, int>> paths;
    int tempDistance = 0;

    for (int i = 0; i < graph.size(); i++) {
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
            paths.push_back(make_pair(path, tempDistance));
        }
        // Visit all of parent's friends. For each one (called v)....
        for (int i = 0; i < graph[parent].size(); i++) {
            int child = graph[parent][i].first;
            int weight = graph[parent][i].second;

            if (distance[child] > distance[parent] + weight) {
                distance[child] = distance[parent] + weight;
                vector<int> newPath(path);
                newPath.push_back(child);
                priorityQueue.push(make_tuple(child, distance[child], newPath));
            }
        }
    }
    this->finalPath = shortestPath(paths);
    this->finalDistance = distance[target];
    return distance;
}

void Dijkstra::printShortestPath(vector<pair<vector<int>, int>> paths) {
    for (int j = 0; j < paths.size(); j++) {
        for (int i = 0; i < paths[j].first.size(); i++) {
            cout << paths[j].first[i] << " ";
        }
        cout << " - Dijkstra Distance: " << paths[j].second << endl;
    }
}

vector<int> Dijkstra::shortestPath(vector<pair<vector<int>, int>> paths) {
    int shortestI = 0;
    for (int i = 1; i < paths.size(); i++) {
        if (paths[shortestI].first.size() > paths[i].first.size())
            shortestI = i;
    }
    return paths[shortestI].first;
}

void Dijkstra::PrintShortestPath(vector<int> &dist, int &start) {
    cout << "\nPrinting the shortest paths for node " << start << ".\n";
    for (int i = start; i < dist.size(); i++) {
        cout << "The distance from node " << start << " to node " << i << " is: " << dist[i] << endl;
    }
}

void Dijkstra::SearchData(int source, int target, Graph g) {
    this->numNodesExplored = 0;
    DijkstraAlgo(g.adjMatrix, source, target);
}