#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>
#include <queue>

using namespace std;

vector<int> kahns(int v, vector<vector<int>> &adj){
    queue<int> q;
    vector<int> indegree(v+1, 0);

    vector<int> res;

    for(int i =1;i<=v;i++){
        for(int j =1;j<=v;j++){
            if(adj[i][j]==1){
                indegree[j]++;
            }
        }
    }

    for(int i =1;i<=v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();
        res.push_back(node);

        for(int i =1;i<=v;i++){
            if(adj[node][i] ==1){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }
    }

    return res;
}


void printAns(vector <int> &v){
    for(int i : v) {
        cout << i << " ";
    }
    cout<<endl;
}

int main(){
    clock_t st = clock();

    int v,e;

    cout << "Enter the no.of vertices and edges: ";
    cin >> v >> e;

    vector <vector<int>> adj(v+1, vector<int>(v+1, 0));

    cout << "Enter the pair of edges (u v) in order: ";

    for(int i =0;i<e;i++){
        int u,t;
        cin >> u >> t;
        adj[u][t] = 1;
    }

    vector <int> fin = kahns(v, adj);
    printAns(fin);

    clock_t et = clock();

    double time = (double(et-st))/CLOCKS_PER_SEC;
    cout << "Time used is "<<fixed <<setprecision(6) << time << " s\n";
    return 0;
}
