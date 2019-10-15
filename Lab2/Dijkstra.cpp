//
// Created by Ryan on 10/12/19.
//
#include "Dijkstra.h"

vector<int> Dijkstra::DijkstraSP(vector<vector<pair<int, int>>> &graph, int &start, int target) {
    cout << "\nGetting the shortest path from " << start << " to all other nodes.\n";
    vector<int> distance;
    vector<int> path;
    vector<pair<vector<int>, int>> paths;
    queue<pair<vector<int>, int>> pathQueue;
    int tempDistance = 0;

    for (int i = 0; i < graph.size(); i++) {
        distance.push_back(INT_MAX); //makes all distances 'infinity'
    }
    priority_queue<tuple<int, int, vector<int>>, vector<tuple<int, int, vector<int>>>, greater<tuple<int, int, vector<int>>>> priorityQueue;
    path.push_back(start);
    priorityQueue.push(make_tuple(start, 0, path));
    distance[start] = 0;
    pathQueue.push(make_pair(path, 0));

    while (!priorityQueue.empty()) {
        // Get min distance vertex from priorityQueue. (Call it parent.)
        int parent = get<0>(priorityQueue.top());
        vector<int> parentPath = get<2>(priorityQueue.top());
        path = pathQueue.front().first;
        tempDistance = pathQueue.front().second;
        pathQueue.pop();
        priorityQueue.pop();

        int lastNode = path[path.size() - 1];
        if (lastNode == target) {
            paths.push_back(make_pair(path, tempDistance));
        }
        // Visit all of parent's friends. For each one (called v)....
        for (int i = 0; i < graph[parent].size(); i++) {
            int child = graph[parent][i].first;
            int weight = graph[parent][i].second;

            // If the distance to child is shorter by going through parent...
            if (distance[child] > distance[parent] + weight) {
                // Update the distance of child.
                distance[child] = distance[parent] + weight;
                // Insert child into the priorityQueue.
                vector<int> newPath(parentPath);
                newPath.push_back(child);
                pathQueue.push(make_pair(newPath, distance[child]));
                priorityQueue.push(make_tuple(child, distance[child], newPath));
            }
        }
    }
    printShortestPath(paths);
    return distance;
}

void Dijkstra::printShortestPath(vector<pair<vector<int>, int>> paths) {
    for (int j = 0; j < paths.size(); j++) {
        for (int i = 0; i < paths[j].first.size(); i++) {
            cout << paths[j].first[i] << " ";
        }
        cout << " - Distance: " << paths[j].second << endl;
    }
}

void Dijkstra::dijkstra(vector<vector<pair<int, int>>> &graph, int dest, int start) {

}

void Dijkstra::PrintShortestPath(vector<int> &dist, int &start) {
    cout << "\nPrinting the shortest paths for node " << start << ".\n";
    for (int i = start; i < dist.size(); i++) {
        cout << "The distance from node " << start << " to node " << i << " is: " << dist[i] << endl;
    }
}