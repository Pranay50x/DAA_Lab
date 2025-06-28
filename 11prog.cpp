#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <string>
#include <limits>
#include <iomanip>
using namespace std;

// Compute & print shortest paths from src using Dijkstra’s algorithm,
// storing each adjacency entry as (neighbor, weight) just like the Prim code.
void dijkstra(int V,
              const vector<vector<pair<int,int>>>& adj,
              int src,
              const vector<string>& names)
{
    vector<int> dist(V, numeric_limits<int>::max());
    vector<int> parent(V, -1);
    vector<bool> vis(V, false);

    // Min-heap of {current_distance, vertex}
    priority_queue< array<int,2>,
                    vector<array<int,2>>,
                    greater<> >
        pq;

    dist[src] = 0;
    pq.push({0, src});   // push {distance, vertex}

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (vis[u]) continue;
        vis[u] = true;

        // Relax all edges (u -> v) stored as (neighbor, weight)
        for (auto& [v, wt] : adj[u]) {
            if (!vis[v] && d + wt < dist[v]) {
                dist[v] = d + wt;
                parent[v] = u;
                pq.push({dist[v], v});   // push {new_distance, vertex}
            }
        }
    }

    // Print shortest distances from src
    cout << "Shortest times from " << names[src] << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "  To " << names[i] << " : ";
        if (dist[i] == numeric_limits<int>::max())
            cout << "No path\n";
        else
            cout << dist[i] << " sec\n";
    }

    // Example: reconstruct path to New York (index 5)
    int target = 5;
    if (dist[target] != numeric_limits<int>::max()) {
        cout << "\nPath to " << names[target] << ":\n";
        vector<int> path;
        for (int v = target; v != -1; v = parent[v]) {
            path.push_back(v);
        }
        for (auto it = path.rbegin(); it != path.rend(); it++) {
            cout << names[*it];
            if (it + 1 != path.rend()) cout << " -> ";
        }
        cout << "\nTotal: " << dist[target] << " sec\n";
    }
}

int main() {
    int V = 7;
    vector<string> names = {
        "San Francisco","Los Angeles","Denver",
        "Dallas","Chicago","New York","Boston"
    };

    // Edge list: (u, v, weight)
    vector<tuple<int,int,int>> edges = {
        {0, 1, 3},
        {0, 2, 4},
        {0, 4, 5},
        {1, 2, 7},
        {1, 3, 5},
        {2, 3, 4},
        {2, 4, 6},
        {3, 4, 5},
        {3, 5, 6},
        {4, 5, 4},
        {4, 6, 3},
        {5, 6, 2}
    };

    // Build adjacency list exactly like Prim’s: store (neighbor, weight)
    vector<vector<pair<int,int>>> adj(V);
    for (auto& [u, v, w] : edges) {
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    int source = 0;  // San Francisco
    dijkstra(V, adj, source, names);
    return 0;
}
