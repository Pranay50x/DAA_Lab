#include <iostream>
#include <vector>
#include <limits>

using namespace std;
const int V = 5;
const vector<char> names = {'A','B','C','D','E'};

int main(){
    vector<vector<int>> g = {
        {0,5,0,4,0},
        {5,0,7,9,0},
        {0,7,0,9,5},
        {4,9,9,0,8},
        {0,0,5,8,0}
    };

    vector<int> key(V, numeric_limits<int>::max()),
                parent(V, -1);
    vector<bool> inMST(V, false);

    key[0] = 0;
    for(int i = 0; i < V-1; ++i){
        int u = -1;
        for(int j = 0; j < V; ++j)
            if(!inMST[j] && (u<0 || key[j] < key[u]))
                u = j;
        inMST[u] = true;

        for(int v = 0; v < V; ++v)
            if(g[u][v] && !inMST[v] && g[u][v] < key[v])
                parent[v] = u, key[v] = g[u][v];
    }

    cout << "Edge   Weight\n";
    int total = 0;
    for(int v = 1; v < V; ++v){
        cout << names[parent[v]] << " - " << names[v]
             << "    " << g[v][parent[v]] << "\n";
        total += g[v][parent[v]];
    }
    cout << "Total length of pipe needed: "
         << total << " meters\n";
    return 0;
}
