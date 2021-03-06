#include <iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<stack>
#include<map>
using namespace std; 


void addEdge(vector<int> adj[], int u, int v, bool directed=true){ 
    adj[u].push_back(v);
		if(!directed){
			adj[v].push_back(u);
		}	
} 

void printAdjList(vector<int> adj[], int V){
	for(int i=0; i<V; i++){
		cout<<i<<" ";
		for(auto x:adj[i]){
			cout<<"->"<<x;
		}
		cout<<endl;
	}
}

void dfs(vector<int> adj[], bool vis[], int start, stack<int> &s){
	vis[start]=true;
	for(auto node:adj[start]){
		if(!vis[node]){
			dfs(adj, vis, node, s);
		}
	}
	s.push(start);
}

 

int main(){
	int V=6;
	vector<int> adj[V];
	addEdge(adj, 5, 2); 
    addEdge(adj, 5, 0); 
    addEdge(adj, 4, 0); 
    addEdge(adj, 4, 1); 
    addEdge(adj, 2, 3); 
    addEdge(adj, 3, 1); 
   

	// printAdjList(adj, V);
	

	stack<int> s;
	bool vis[V];
	// bool* vis = new bool[V]; 
	for (int i = 0; i < V; ++i)
	{
		vis[i]=false;
	}



	for (int i = 0; i < V; ++i)
	{
		if(vis[i]==false){
			dfs(adj, vis, i,s);
		}
	}
	
	while(!s.empty()){
		int stop=s.top();
		s.pop();
		cout<<stop<<endl;
	}
	return 0;
}







