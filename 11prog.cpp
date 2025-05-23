#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <iomanip>

using namespace std;
const int V = 7;
const vector<string> names = {
    "San Francisco","Los Angeles","Denver",
    "Dallas","Chicago","New York","Boston"
};

int main() {
    vector<vector<int>> g = {
        {0,3,4,0,5,0,0},
        {3,0,7,5,0,0,0},
        {4,7,0,4,6,0,0},
        {0,5,4,0,5,6,0},
        {5,0,6,5,0,4,3},
        {0,0,0,6,4,0,2},
        {0,0,0,0,3,2,0}
    };

    vector<int> dist(V, INT_MAX), parent(V, -1);
    vector<bool> vis(V, false);
    dist[0] = 0;

    for (int i = 0; i < V; ++i) {
        // find unvisited with smallest dist
        int u = -1;
        for (int j = 0; j < V; ++j) {
            if (!vis[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }
        if (u == -1 || dist[u] == INT_MAX) break;
        vis[u] = true;

        // relax edges
        for (int v = 0; v < V; ++v) {
            if (g[u][v] && !vis[v] && dist[u] + g[u][v] < dist[v]) {
                dist[v] = dist[u] + g[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "Shortest times from " << names[0] << ":\n";
    for (int i = 0; i < V; ++i) {
        cout << "  To " << setw(13) << left << names[i] << " : "
             << (dist[i] == INT_MAX ? string("No path") : to_string(dist[i]) + " sec")
             << "\n";
    }

    // Reconstruct path to New York (index 5)
    if (dist[5] != INT_MAX) {
        cout << "\nPath to New York:\n";
        vector<int> path;
        for (int v = 5; v != -1; v = parent[v])
            path.push_back(v);
        for (auto it = path.rbegin(); it != path.rend(); ++it) {
            cout << names[*it];
            if (it + 1 != path.rend()) cout << " -> ";
        }
        cout << "\nTotal: " << dist[5] << " sec\n";
    }

    return 0;
}
