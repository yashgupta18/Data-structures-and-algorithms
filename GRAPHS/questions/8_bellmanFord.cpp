#include <iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<set>
#include<stack>
#include <limits.h> 
#include <utility>
#include <functional>
#include <stdio.h> 
#include<map>
#define V 5
#define E 8
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



vector<int> bellman(int graph[V][V], vector<pair<int, int> >edgeList, vector<int> dist){
	for (int i = 0; i < V-1; ++i)
	{
		for (int j = 0; j < E; ++j)
		{
			int u=edgeList[j].first;
			int v=edgeList[j].second;
			if(dist[u]+ graph[u][v]< dist[v]){
				dist[v]=dist[u]+graph[u][v];
			}
		}
	}
	return dist;
}




int main(){ 
    int graph[V][V] = { { 0, -1, 4, 0, 0 }, 
                        { 0, 0, 3, 2, 2}, 
                        { 0, 0,0,0,0}, 
                        { 0, 1, 5, 0, 0 }, 
                        { 0, 0, 0, -3, 0}, 
                    };                        
  	
  	vector<pair<int, int> >edgeList;
  	edgeList.push_back(make_pair(0,1));
  	edgeList.push_back(make_pair(0,2));
  	edgeList.push_back(make_pair(1,2));
  	edgeList.push_back(make_pair(1,3));
  	edgeList.push_back(make_pair(1,4));
  	edgeList.push_back(make_pair(3,1));
  	edgeList.push_back(make_pair(3,2));
  	edgeList.push_back(make_pair(4,2));

  	vector<int> dist(V, INT_MAX);
  	cout<<"BEFORE"<<endl;
  	for (int i = 0; i < V; ++i)
  	{
  		
  		cout<<dist[i]<<" ";
  	}
  	cout<<endl;
	dist[0]=0;
    vector<int> newDist=bellman(graph,edgeList,dist); 
  	
  	cout<<"AFTER"<<endl;
  	for (int i = 0; i < V; ++i)
  	{

  		cout<<newDist[i]<<" ";
  	}
  	
    return 0; 
}







