#include <iostream>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

void findTopSort(int node, vector<int> &visited, stack<int> &st, vector<int> adj[]){
    visited[node] =1;

    for(auto x : adj[node]){
        if(!visited[x]){
            findTopSort(x, visited, st,adj);
        }
    }
    st.push(node);
}

vector<int> topSort(int n, vector<int> adj[]){
    stack <int> st;
    vector<int> visited(n+1,0);

    for(int i =1;i<n;i++){
        if(visited[i]==0){
            findTopSort(i, visited,st, adj);
        }
    }
    vector<int> top;
    while(!st.empty()){
        top.push_back(st.top());
        st.pop();
    }
    return top;
}

void addEdge(vector<int>adj[], int u, int v){
    adj[u].push_back(v);
    // adj[v].push_back(u); made the graph undirected;
}


int main(){
    clock_t st,et;
    st = clock();
    cout << "Enter the number of vertices and edges: " ;
    int V,E;
    cin >> V >> E;

    vector<int> adj[V+1]; //declaring and using array of vectors

    cout << "Enter pair of edges and vertices: \n";
    for(int i = 0;i<E;i++){
        int u,v;
        cin >> u >> v;
        addEdge(adj, u ,v);
    }
    cout << "Topological Sort: \n";
    vector <int> ts = topSort(V-1,adj);
    for(int x : ts){
        cout << x << " ";
    }
    cout << endl;
    et = clock();
    double time_used = (double(et-st))/CLOCKS_PER_SEC;
    cout << "Time used is: " << fixed << setprecision(6) << time_used << " s\n";
    return 0;
}
