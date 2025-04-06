#include <iostream>
#include <ctime>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

class Solution{
	public:
		// unchanged
		vector<int> bfsGraph(int V, vector<int> adj[]){
			vector<int> vis(V+1, 0); ;
			vis[1] = 1;
			queue<int> q;

			vector<int> bfs;

			q.push(1);

			while(!q.empty()){
				int node = q.front();
				q.pop();
				bfs.push_back(node);

				for(auto x : adj[node]){
					if(!vis[x]){
						vis[x] = 1;
						q.push(x);
					}
				}
			}
			return bfs;
		}
};

void addEdge(vector<int> adj[], int u, int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void printA(const vector<int> &ans){
	for(int x : ans){
		cout << x << " ";
	}
	cout << "\n";
}

int main(){
	int V, E;
	cout << "Enter number of vertices and edges: ";
	cin >> V >> E;

	// make room for 1..V
	vector<int>* adj = new vector<int>[V+1];

	cout << "Enter each edge (u v) on its own line:\n";
	for(int i = 0; i < E; i++){
		int u, v;
		cin >> u >> v;
		addEdge(adj, u, v);
	}

	clock_t st = clock();

	Solution sol;
	vector<int> fin = sol.bfsGraph(V, adj);

	printA(fin);

	clock_t et = clock();
	double time = double(et - st) / CLOCKS_PER_SEC;
	cout << "Time used is: " << fixed << setprecision(6) << time << " s\n";

	delete[] adj;
	return 0;
}
