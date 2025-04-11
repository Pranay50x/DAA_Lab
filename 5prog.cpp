#include <iostream>
#include <ctime>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

class Solution {
public:
    vector<int> bfsGraph(int V, vector<vector<int>>& adjMat) {
        vector<int> vis(V + 1, 0);
        vis[1] = 1;
        queue<int> q;

        vector<int> bfs;
        q.push(1);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            bfs.push_back(node);

            for (int i = 1; i <= V; i++) {
                if (adjMat[node][i] == 1 && !vis[i]) {
                    vis[i] = 1;
                    q.push(i);
                }
            }
        }

        return bfs;
    }
};

void printA(const vector<int>& ans) {
    for (int x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> adjMat(V + 1, vector<int>(V + 1, 0));

    cout << "Enter each edge (u v) on its own line:\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adjMat[u][v] = 1;
        adjMat[v][u] = 1; // because the graph is undirected
    }

    clock_t st = clock();

    Solution sol;
    vector<int> fin = sol.bfsGraph(V, adjMat);

    printA(fin);

    clock_t et = clock();
    double time = double(et - st) / CLOCKS_PER_SEC;
    cout << "Time used is: " << fixed << setprecision(6) << time << " s\n";

    return 0;
}
