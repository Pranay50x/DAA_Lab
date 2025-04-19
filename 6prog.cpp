#include <iostream>
#include <iomanip>
#include <vector>
#include <stack>
#include <ctime>

using namespace std;

void addEdge(vector<vector<bool>> &matrix, int u, int v) {
    matrix[u][v] = true;
    matrix[v][u] = true;
}

void dfsStack(int V, vector<vector<bool>> &matrix, int start) {
    vector<bool> visited(V+1, false);
    stack<int> st;
    st.push(start);

    while(!st.empty()) {
        int node = st.top();
        st.pop();

        if(!visited[node]) {
            cout << node << " ";
            visited[node] = true;
        }

        // Check neighbors in reverse order to maintain DFS sequence
        for(int i = V; i >= 1; i--) {
            if(matrix[node][i] && !visited[i]) {
                st.push(i);
            }
        }
    }
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
    for(int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(matrix, u, v);
    }

    cout << "DFS Traversal: \n";
    dfsStack(V, matrix, 1);
    cout << endl;

    et = clock();
    double time_used = (double)(et - st) / CLOCKS_PER_SEC;
    cout << "Time used is: " << fixed << setprecision(6) << time_used << " s\n";

    return 0;
}
