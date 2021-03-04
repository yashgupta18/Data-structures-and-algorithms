#include <iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<set>
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


void dijkstra(int graph[V][V], int src){

		int dist[V];
		for (int i = 0; i < V; ++i)
		{
			//all distances to infinity
			// dist[i.first]=INT_MAX;
			dist[i]=INT_MAX;
		} 

		//Make set to find node with minimum distance as first , city as second pair
		set<pair<int,int> > s;

		dist[src]=0;
		s.insert(make_pair(0, src));

		while(!s.empty()){

			auto p = *(s.begin());

			//node with minimum distance will always be first node in set
			int u=p.second;

			//delete beginning node
			s.erase(s.begin());

			//iterate over nodes adjacent to current node using m
			for(int v=0; v<V; v++){
				if(graph[u][v]){
				// check if dist of src + node dist is less than dist
				if(dist[u] + graph[u][v] < dist[v]){
					//In Set, updation is not possible, so we remove the old pair and add th new pair
					
					// 	auto f = i.find(make_pair(dist[dest], dest));
					auto f = s.find(make_pair(dist[v], v));
					if(f!=s.end()){
						s.erase(f);
					}

					//insert new pair
					dist[v]=dist[u] + graph[u][v];
					s.insert(make_pair(dist[v], v));	
				}
			}
			}
		}
			
		//print dist from all other nodes
		for (int i = 0; i < V; ++i)
		{
			cout<<dist[i]<<" ";
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







