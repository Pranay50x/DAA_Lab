#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <iomanip>
using namespace std;

// Compute & print shortest paths from src using Dijkstra’s algorithm
void dijkstra(const vector<vector<int>>& g, int src, const vector<string>& names) {
    int V = g.size();
    vector<int> dist(V, numeric_limits<int>::max()), parent(V, -1);
    vector<bool> vis(V, false);
    dist[src] = 0;

    for (int i = 0; i < V; ++i) {
        // pick nearest unvisited
        int u = -1;
        for (int j = 0; j < V; ++j) {
            if (!vis[j] && (u < 0 || dist[j] < dist[u]))
                u = j;
        }
        if (u < 0 || dist[u] == numeric_limits<int>::max()) break;
        vis[u] = true;

        // relax edges
        for (int v = 0; v < V; ++v) {
            if (g[u][v] && !vis[v] && dist[u] + g[u][v] < dist[v]) {
                dist[v] = dist[u] + g[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "Shortest times from " << names[src] << ":\n";
    for (int i = 0; i < V; ++i) {
        cout << "  To " << setw(13) << left << names[i] << " : "
             << (dist[i] == numeric_limits<int>::max()
                     ? string("No path")
                     : to_string(dist[i]) + " sec")
             << "\n";
    }

    // example: path to New York
    int target = 5;  // index for New York
    if (dist[target] != numeric_limits<int>::max()) {
        cout << "\nPath to " << names[target] << ":\n";
        vector<int> path;
        for (int v = target; v != -1; v = parent[v])
            path.push_back(v);
        for (auto it = path.rbegin(); it != path.rend(); ++it) {
            cout << names[*it];
            if (it + 1 != path.rend()) cout << " -> ";
        }
        cout << "\nTotal: " << dist[target] << " sec\n";
    }
}

int main() {
    vector<string> names = {
        "San Francisco","Los Angeles","Denver",
        "Dallas","Chicago","New York","Boston"
    };
    vector<vector<int>> g = {
        {0,3,4,0,5,0,0},
        {3,0,7,5,0,0,0},
        {4,7,0,4,6,0,0},
        {0,5,4,0,5,6,0},
        {5,0,6,5,0,4,3},
        {0,0,0,6,4,0,2},
        {0,0,0,0,3,2,0}
    };

    dijkstra(g, 0, names);  // run from San Francisco (index 0)
    return 0;
}
