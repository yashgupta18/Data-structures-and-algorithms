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

bool DirectedCycle(vector<int> adj[], int V, bool vis[], int start, bool anc[]){
	vis[start]=true;
	anc[start]=true;
	for(auto i:adj[start]){
		//if not visited, check if it has cycle
		if(!vis[i]){
			if(DirectedCycle(adj, V, vis, i, anc)){
				return true;
			}
		}
		else if(anc[i]){
			return true;
		}
	}
	anc[start]=false;
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
    addEdge(adj, 4, 2); 
   

	// printAdjList(adj, V);
	bool vis[V];
	bool anc[V];
	for (int i = 0; i < V; ++i)
	{
		vis[i]=false;
	}

	bool ans=DirectedCycle(adj, V, vis,0, anc);
	cout<<ans;
	return 0;
}







