#include <iostream>
#include <iomanip>
#include <vector>
#include <stack>
#include <ctime>

using namespace std;

vector<int> dfsGraph(int V, vector<vector<int>> &adj) {
    vector<int> vis(V+1, 0);
    vector<int> dfs;
    stack<int> st;
    st.push(1);
    while (!st.empty()) {
        int node = st.top();
        st.pop();
        if (!vis[node]) {
            vis[node] = 1;
            dfs.push_back(node);
            for (int i = V; i >= 1; --i) {
                if (adj[node][i] && !vis[i]) {
                    st.push(i);
                }
            }
        }
    }
    return dfs;
}

void printAns(const vector<int> &v) {
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    clock_t st = clock();
    int v, e;
    cout << "Enter the no. of vertices and edges: ";
    cin >> v >> e;
    vector<vector<int>> adj(v+1, vector<int>(v+1, 0));
    cout << "Enter each edge (u v) on its own line: \n";
    for (int i = 0; i < e; ++i) {
        int u, w;
        cin >> u >> w;
        adj[u][w] = 1;
        adj[w][u] = 1;
    }
    vector<int> answer = dfsGraph(v, adj);
    printAns(answer);
    clock_t et = clock();
    double time = double(et - st) / CLOCKS_PER_SEC;
    cout << "Time used is " << fixed << setprecision(6) << time << " s\n";
    return 0;
}
