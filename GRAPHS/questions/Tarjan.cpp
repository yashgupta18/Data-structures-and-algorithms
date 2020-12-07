#include<iostream>
#include<map>
#include<string>
#include<stack>
#include<list>
#include<unordered_map>
#include<queue>
// #define V 5
 #define ROW 5
 #define COL 5
using namespace std;
// template<typename T>
class Graph{
	int V;  
    list<int> *adj;

   	// map<T, list<T> > adj;
public:
	Graph(int V)
	{
		this->V= V;
		adj=new list<int>[V];
	}


	// void addEdge(int x, int y){
	// 	adj[x].push_back(y);
	// 	adj[y].push_back(x);
	// }

	void addEdge(int x, int y, bool directed=true){
		adj[x].push_back(y);
		if(!directed){
			adj[y].push_back(x);
		}	
	}

	void printAdjList(int x){
		for(int i=x; i<V; i++){
			cout<<i<<" ";
			for(auto x:adj[i]){
				cout<<"->"<<x;
			}
			cout<<endl;
		}
	}

	// https://www.geeksforgeeks.org/bridge-in-a-graph/
	// a bridge is an edge removing which increases number of disconnected components.
	void dfs(int u,bool vis[],int low[],int disc[],int parent[], int &time){
	vis[u]=true;
	low[u]=disc[u]=++time;
	// parent[u]=
	for(auto v:adj[u]){
		if(!vis[v]){
			parent[v]=u;
			dfs(v, vis, low, disc, parent,time);
			low[u]=min(low[u], low[v]);
			if(low[v]>disc[u]){
				cout<<u<<" "<<v<<endl;
			}
		}
		else if(v!=parent[u]){
			low[u]=min(low[u], disc[v]);
		}
	}

}

	void bridge(){
		bool vis[V];
		int low[V];
		int disc[V];
		int parent[V];
		for (int i = 0; i < V; ++i)
		{
			vis[i]=false;
			parent[i]=-1;
		}

		int time=0;
		for (int i = 0; i < V; ++i)
		{
			if(!vis[i]){
				dfs(i,vis,low,disc,parent, time);
			}
		}
	}


};

int main(){
	// GRAPH

	// 1----0------3
	// |   /	   |
	// |  /		   |
	// 2		   4


	Graph g1(5); 
    g1.addEdge(1, 0); 
    g1.addEdge(0, 2); 
    g1.addEdge(2, 1); 
    g1.addEdge(0, 3); 
    g1.addEdge(3, 4); 
    g1.bridge(); 
   

	// // // print Graph list
	// g.printAdjList(0);

	// //BFS TRAVERSAL
	// g1.dfs(0);

	return 0;
}













