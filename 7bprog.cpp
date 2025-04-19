#include <iostream>
#include <vector>
#include <queue>
#include <ctime>
#include <iomanip>

using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
}

vector<int> kahnTopSort(int n, vector<int> adj[]) {
    vector<int> in_degree(n+1, 0);
    for (int i = 1; i <= n; i++) {
        for (auto x : adj[i]) {
            in_degree[x]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> top_order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        top_order.push_back(u);

        for (auto x : adj[u]) {
            in_degree[x]--;
            if (in_degree[x] == 0) {
                q.push(x);
            }
        }
    }

    if ((int)top_order.size() != n) {
        cout << "There exists a cycle in the graph, topological sort not possible." << endl;
        return {};
    }

    return top_order;
}

int main() {
    clock_t st, et;
    st = clock();

    cout << "Enter the number of vertices and edges: ";
    int V, E;
    cin >> V >> E;

    vector<int> adj[V+1];

    cout << "Enter pair of edges and vertices: \n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(adj, u, v);
    }

    cout << "Topological Sort using Kahn's Algorithm: \n";
    vector<int> ts = kahnTopSort(V, adj);
    for (int x : ts) {
        cout << x << " ";
    }
    cout << endl;

    et = clock();
    double time_used = (double)(et - st) / CLOCKS_PER_SEC;
    cout << "Time used is: " << fixed << setprecision(6) << time_used << " s\n";

    return 0;
}
