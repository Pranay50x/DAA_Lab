#include <iostream>
#include <ctime>
#include <vector>
#include <iomanip>

using namespace std;

class Solution {
public:
    void dfsHelper(int node, vector<vector<int>>& adjMat, vector<int>& vis, vector<int>& dfs) {
        vis[node] = 1;
        dfs.push_back(node);

        for (int i = 1; i < adjMat.size(); i++) {
            if (adjMat[node][i] == 1 && !vis[i]) {
                dfsHelper(i, adjMat, vis, dfs);
            }
        }
    }

    vector<int> dfsGraph(int V, vector<vector<int>>& adjMat) {
        vector<int> vis(V + 1, 0);
        vector<int> dfs;
        dfsHelper(1, adjMat, vis, dfs); // start DFS from node 1
        return dfs;
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
        adjMat[v][u] = 1;
    }

    clock_t st = clock();

    Solution sol;
    vector<int> fin = sol.dfsGraph(V, adjMat);

    printA(fin);

    clock_t et = clock();
    double time = double(et - st) / CLOCKS_PER_SEC;
    cout << "Time used is: " << fixed << setprecision(6) << time << " s\n";

    return 0;
}
