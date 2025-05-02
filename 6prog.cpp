#include <iostream>
#include <iomanip>
#include <vector>
#include <stack>
#include <ctime>
using namespace std;

vector<int> dfsGraph(int V, vector<vector<int>> &adj) {
    stack<int> st;
    vector<int> vis(V+1, 0);
    vector<int> dfs;
    
    vis[1] = 1;
    st.push(1);
    
    while(!st.empty()) {
        int node = st.top();
        st.pop();
        dfs.push_back(node);
        
        for(int i = V; i >= 1; i--) {
            if(adj[node][i] == 1 && !vis[i]) {
                vis[i] = 1;
                st.push(i);
            }
        }
    }
    return dfs;
}

void printAns(vector<int> &v) {
    for(int i : v) {
        cout << i << " ";
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
    for(int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    
    vector<int> answer = dfsGraph(v, adj);
    printAns(answer);
    
    clock_t et = clock();
    double time = (double(et-st))/CLOCKS_PER_SEC;
    cout << "Time used is " << fixed << setprecision(6) << time << " s\n";
    return 0;
}
