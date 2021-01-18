#include <iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<stack>
#include<map>
using namespace std; 


void addEdge(vector<int> adj[], int u, int v, bool directed=false){ 
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

bool undirectedCycle(vector<int> adj[], int V, bool vis[], int start, int parent){
	vis[start]=true;
	for(auto node:adj[start]){
		if(!vis[node]){
			if(undirectedCycle(adj, V, vis, node, start)){
				return true;
			}
		}
		else if(node!=parent){
			return true;
		}
	}
	return false;
	
}



int main(){
	int V=5;
	vector<int> adj[V];
	addEdge(adj, 0, 1); 
    addEdge(adj, 0, 4); 
    // addEdge(adj, 1, 2); 
    // addEdge(adj, 1, 3); 
    // addEdge(adj, 1, 4); 
    addEdge(adj, 2, 3); 
    addEdge(adj, 3, 4); 
   

	printAdjList(adj, V);
	bool vis[V];
	for (int i = 0; i < V; ++i)
	{
		vis[i]=false;
	}

	

	bool ans=undirectedCycle(adj, V, vis,0, -1);
	cout<<ans;
	return 0;
}







