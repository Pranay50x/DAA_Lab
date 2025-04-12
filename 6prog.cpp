#include <iostream>
#include <iomanip>
#include <vector>
#include <stack>
#include <algorithm>
#include <ctime>

using namespace std;

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}


void dfsStack(int V, vector<int> adj[], int start){
    vector<bool> visited(V+1, false); // this is array of vectors the adj[] one
    stack <int> st;
    // pushing the first node into the stack
    st.push(start);


    while(!st.empty()){
        int node = st.top();

        st.pop();
        //returning the output and marking the node as visited in the array
        if(!visited[node]){
            cout << node << " ";
            visited[node] =true;
        }
        // traversing the adjaceny matrix and then pushing the neighbour of the node we visited already.
        for(int i = adj[node].size()-1; i>=0;i--){
            int neighbour = adj[node][i];

            if(!visited[neighbour]){
                st.push(neighbour);
            }
        }
    }
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
    cout << "DFS Traversal: \n";
    dfsStack(V, adj, 1);
    cout << endl;
    et = clock();
    double time_used = (double(et-st))/CLOCKS_PER_SEC;
    cout << "Time used is: " << fixed << setprecision(6) << time_used << " s\n";
    return 0;
}
