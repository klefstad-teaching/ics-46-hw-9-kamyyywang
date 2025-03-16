#include "dijkstras.h"

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
    int n = G.numVertices;
    vector<int> distances(n, INF);
    distances[source] = 0;
    previous.resize(n, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, source});
    
    while (!pq.empty()) {
        auto [dist, u] = pq.top(); pq.pop();
        if (dist > distances[u]) continue;
        for (const auto& edge : G[u]) {
            int v = edge.dst, weight = edge.weight;
            if (distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                previous[v] = u;
                pq.push({distances[v], v});
            }
        }
    }
    return distances;
}

vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination) {
    vector<int> path;
    if (distances[destination] == INF) return {};
    
    for (int v = destination; v != -1; v = previous[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    if (path.size() == 1 && path[0] != 0) {
        return {};
    }
    return path;
}

void print_path(const vector<int>& path, int total) {
    for (size_t i = 0; i < path.size() && !path.empty(); ++i) {
        cout << path[i] << " ";
    }
    cout << "\nTotal cost is " << total << endl;
}
