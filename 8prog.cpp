#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <functional>
using namespace std;

int primMST_list(int V, const vector<vector<pair<int,int>>>& adj, int start) {
    vector<bool> vis(V,false);
    priority_queue<array<int,3>,
                   vector<array<int,3>>,
                   greater<>> pq;
    pq.push({0, start, -1});

    int total = 0;
    cout << "Edges in MST:\n";
    while (!pq.empty()) {
        auto [w,u,p] = pq.top(); pq.pop();
        if (vis[u]) continue;
        vis[u] = true;
        if (p!=-1) {
            cout << char('A'+p) << " - " << char('A'+u)
                 << " : " << w << "\n";
            total += w;
        }
        for (auto& [v,wt] : adj[u]){
            if (!vis[v])
                pq.push({wt,v,u});
        }
    }
    return total;
}

int main(){
    int V = 6, start = 5;
    vector<tuple<int,int,int>> edges = {
        {0,1,5},{0,3,6},{0,2,2},{0,4,4},
        {1,2,2},{2,4,3},{3,5,7},{4,5,8},{3,4,3}
    };

    vector<vector<pair<int,int>>> adj(V);
    for (auto& [u,v,w] : edges) {
        adj[u].emplace_back(v,w);
        adj[v].emplace_back(u,w);
    }

    int res = primMST_list(V, adj, start);

    cout << "Total MST Weight: "
         << res << "\n";
    return 0;
}
