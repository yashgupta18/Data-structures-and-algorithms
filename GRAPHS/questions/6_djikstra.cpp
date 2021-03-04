#include <iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<stack>
#include <limits.h> 
#include <stdio.h> 
#include<map>
#define V 9
using namespace std; 

void addEdge(vector<int> adj[], int u, int v, bool directed=false){ 
    adj[u].push_back(v);
		if(!directed){
			adj[v].push_back(u);
		}	
} 

void printAdjList(vector<int> adj[]){
	for(int i=0; i<V; i++){
		cout<<i<<" ";
		for(auto x:adj[i]){
			cout<<"->"<<x;
		}
		cout<<endl;
	}
}

int minVal(bool vis[], int dist[]){
	int min=INT_MAX, min_index;
	for (int i = 0; i < V; ++i)
	{
		if(vis[i]==false && dist[i]<min){
			min=dist[i];
			min_index=i;
		}
	}
	// cout<<"Min index= "<<min_index<<endl;
	return min_index;
}


void dijkstra(int graph[V][V], int source){
	bool vis[V];
	int dist[V];

	for (int i = 0; i < V; ++i)
	{
		vis[i]=false;
		dist[i]=INT_MAX;
	}

	dist[source]=0;

	for (int i = 0; i < V-1; ++i)
	{
		int u= minVal(vis, dist);
		vis[u]=true;

		for (int v = 0; v < V; ++v)
		{
			//if edge btw u and v
			if(graph[u][v]){
				if(dist[u]+ graph[u][v]<dist[v]){
					dist[v]=dist[u]+ graph[u][v];
				}
			}
		}
	}

	for (int i = 0; i < V; ++i)
	{
		cout<<dist[i]<<endl;
	}

	
}




int main(){ 
    /* Let us create the example graph discussed above */
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
  
    dijkstra(graph,0); 
  	
  	
    return 0; 
}







