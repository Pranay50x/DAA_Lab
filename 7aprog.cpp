#include <iostream>
#include <vector>
#include <stack>
#include <ctime>
#include <iomanip>

using namespace std;

void topoDFS(int node, vector<int> &vis, stack<int> &st, vector<vector<int>> &adj, int V) {
    vis[node] = 1;
    for (int i = 1; i <= V; ++i) {
        if (adj[node][i] && !vis[i]) {
            topoDFS(i, vis, st, adj, V);
        }
    }
    st.push(node);
}

vector<int> topSortGraph(int V, vector<vector<int>> &adj) {
    vector<int> vis(V+1, 0);
    stack<int> st;
    for (int i = 1; i <= V; ++i) {
        if (!vis[i]) {
            topoDFS(i, vis, st, adj, V);
        }
    }
    vector<int> order;
    while (!st.empty()) {
        order.push_back(st.top());
        st.pop();
    }
    return order;
}

void printAns(const vector<int> &v) {
    for (int x : v) {
        cout << x << " ";
    }
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
    vector<int> result = topSortGraph(V, adj);
    printAns(result);
    clock_t et = clock();
    double time = double(et - st) / CLOCKS_PER_SEC;
    cout << "Time used is " << fixed << setprecision(6) << time << " s\n";
    return 0;
}
