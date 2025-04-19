#include <iostream>
#include <vector>
#include <queue>
#include <ctime>
#include <iomanip>

using namespace std;

void addEdge(vector<vector<bool>> &matrix, int u, int v) {
    matrix[u][v] = true;
}

vector<int> kahnTopSort(int n, vector<vector<bool>> &matrix) {
    vector<int> in_degree(n+1, 0);

    // Calculate in-degrees
    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
            if (matrix[u][v]) {
                in_degree[v]++;
            }
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

        // Process all neighbors
        for (int v = 1; v <= n; v++) {
            if (matrix[u][v]) {
                if (--in_degree[v] == 0) {
                    q.push(v);
                }
            }
        }
    }

    if (top_order.size() != n) {
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

    // Initialize adjacency matrix (V+1 x V+1 for 1-based indexing)
    vector<vector<bool>> matrix(V+1, vector<bool>(V+1, false));

    cout << "Enter pair of edges and vertices: \n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(matrix, u, v);
    }

    cout << "Topological Sort using Kahn's Algorithm: \n";
    vector<int> ts = kahnTopSort(V, matrix);
    for (int x : ts) {
        cout << x << " ";
    }
    cout << endl;

    et = clock();
    double time_used = (double)(et - st) / CLOCKS_PER_SEC;
    cout << "Time used is: " << fixed << setprecision(6) << time_used << " s\n";

    return 0;
}
