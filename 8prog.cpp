#include <vector>
#include <iostream>


using namespace std;

int primMST(int V, vector<pair<int,int>> adj[], int start) {
    vector<int> key(V, INT_MAX), parent(V, -1);
    vector<bool> inMST(V, false);

    key[start] = 0;

    for (int count = 0; count < V; count++) {
        int u = -1, minKey = INT_MAX;
        for (int i = 0; i < V; i++)
            if (!inMST[i] && key[i] < minKey) {
                minKey = key[i];
                u = i;
            }

        inMST[u] = true;

        for (auto &[v, w] : adj[u])
            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                parent[v] = u;
            }
    }

    int totalWeight = 0;
    cout << "Edges in MST:\n";
    for (int i = 0; i < V; i++) {
        if (parent[i] != -1) {
            cout << parent[i] << " - " << i << " : " << key[i] << "\n";
            totalWeight += key[i];
        }
    }
    return totalWeight;
}

int main() {
    int V = 6;
    vector<vector<int>> edges = {
        {0,1,5}, {0,3,6}, {0,2,2}, {0,4,4},
        {1,2,2}, {2,4,3}, {3,5,7}, {4,5,8},
        {3,4,3}
    };

    vector<pair<int,int>> adj[V];
    for (auto &e : edges) {
        adj[e[0]].emplace_back(e[1], e[2]);
        adj[e[1]].emplace_back(e[0], e[2]);
    }

    int start = 5;
    int weight = primMST(V, adj, start);
    cout << "Total MST Weight: " << weight << "\n";
}
