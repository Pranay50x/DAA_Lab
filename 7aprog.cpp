#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>
#include <stack>

using namespace std;

void findTopSort(int node, vector<int> &visited, stack<int> &st, vector<vector<bool>> &matrix, int V) {
    visited[node] = 1;

    // Check all possible neighbors
    for (int x = 1; x <= V; x++) {
        if (matrix[node][x] && !visited[x]) {
            findTopSort(x, visited, st, matrix, V);
        }
    }
    st.push(node);
}

vector<int> topSort(int n, vector<vector<bool>> &matrix) {
    stack<int> st;
    vector<int> visited(n+1, 0);

    // Corrected loop to process all nodes
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            findTopSort(i, visited, st, matrix, n);
        }
    }

    vector<int> top;
    while (!st.empty()) {
        top.push_back(st.top());
        st.pop();
    }
    return top;
}

void addEdge(vector<vector<bool>> &matrix, int u, int v) {
    matrix[u][v] = true;
}

int main() {
    clock_t st, et;
    st = clock();

    cout << "Enter the number of vertices and edges: ";
    int V, E;
    cin >> V >> E;

    // Initialize adjacency matrix
    vector<vector<bool>> matrix(V+1, vector<bool>(V+1, false));

    cout << "Enter pair of edges and vertices: \n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(matrix, u, v);
    }

    cout << "Topological Sort: \n";
    vector<int> ts = topSort(V, matrix);
    for (int x : ts) {
        cout << x << " ";
    }
    cout << endl;

    et = clock();
    double time_used = (double)(et - st) / CLOCKS_PER_SEC;
    cout << "Time used is: " << fixed << setprecision(6) << time_used << " s\n";

    return 0;
}
