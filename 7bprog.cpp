#include <iostream>
#include <vector>
#include <queue>
#include <ctime>
#include <iomanip>

using namespace std;

vector<int> kahnTopSortGraph(int V, vector<vector<int>> &adj) {
    vector<int> in_deg(V+1, 0), order;
    for (int u = 1; u <= V; ++u)
        for (int v = 1; v <= V; ++v)
            if (adj[u][v])
                in_deg[v]++;
    queue<int> q;
    for (int i = 1; i <= V; ++i)
        if (in_deg[i] == 0)
            q.push(i);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (int v = 1; v <= V; ++v) {
            if (adj[u][v] && --in_deg[v] == 0)
                q.push(v);
        }
    }
    return order.size() == V ? order : vector<int>{};
}

void printAns(const vector<int> &v) {
    for (int x : v)
        cout << x << " ";
    cout << endl;
}

int main() {
    clock_t st = clock();
    int V, E;
    cout << "Enter the no. of vertices and edges: ";
    cin >> V >> E;
    vector<vector<int>> adj(V+1, vector<int>(V+1, 0));
    cout << "Enter each edge (u v) on its own line: \n";
    for (int i = 0; i < E; ++i) {
        int u, w;
        cin >> u >> w;
        adj[u][w] = 1;
    }
    vector<int> result = kahnTopSortGraph(V, adj);
    printAns(result);
    clock_t et = clock();
    double time = double(et - st) / CLOCKS_PER_SEC;
    cout << "Time used is " << fixed << setprecision(6) << time << " s\n";
    return 0;
}
