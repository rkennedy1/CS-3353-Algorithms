//
// Created by Ryan on 10/12/19.
//

/*
int myDijkstra::Dijkstra(Graph list, int source, int target) {
    vector<int> min_distance( list.V, INT_MAX );
    min_distance[source] = 0;
    set< pair<int,int> > active_vertices;
    active_vertices.insert( {0,source} );

    while(!active_vertices.empty()) {
        int where  = active_vertices.begin()->second;
        if(where == target) return min_distance[where];
        active_vertices.erase(active_vertices.begin());
        for (auto i : list[where])

    }

}*/