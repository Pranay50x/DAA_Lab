// Prim’s MST using an adjacency-matrix
#include <iostream>
#include <vector>
#include <limits>    // for INT_MAX
using namespace std;

// Compute & print MST, return total weight
int primMST_matrix(int V, const vector<vector<int>>& g, int start) {
    vector<int> key(V, numeric_limits<int>::max()), parent(V, -1);
    vector<bool> inMST(V, false);
    key[start] = 0;

    for (int count = 0; count < V; ++count) {
        // pick next u
        int u = -1;
        for (int i = 0; i < V; ++i) {
            if (!inMST[i] && (u < 0 || key[i] < key[u]))
                u = i;
        }
        inMST[u] = true;

        // relax edges from u
        for (int v = 0; v < V; ++v) {
            if (g[u][v] != 0 && !inMST[v] && g[u][v] < key[v]) {
                key[v]    = g[u][v];
                parent[v] = u;
            }
        }
    }

    int total = 0;
    cout << "Edges in MST (matrix):\n";
    for (int v = 0; v < V; ++v) {
        if (parent[v] != -1) {
            cout << char('A' + parent[v]) << " - " << char('A' + v) << " : " << key[v] << "\n";
            total += key[v];
        }
    }
    return total;
}

int main() {
    int V = 6, start = 5;  // start at 'F'
    vector<vector<int>> g = {
        {0, 5, 2, 6, 4, 0},
        {5, 0, 2, 0, 0, 0},
        {2, 2, 0, 0, 3, 0},
        {6, 0, 0, 0, 3, 7},
        {4, 0, 3, 3, 0, 8},
        {0, 0, 0, 7, 8, 0}
    };

    int total = primMST_matrix(V, g, start);
    cout << "Total MST Weight (matrix): " << total << "\n";
    return 0;
}
