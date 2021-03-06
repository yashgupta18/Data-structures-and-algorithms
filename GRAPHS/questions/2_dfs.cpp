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

	void dfs_Util(int node, bool vis[]){
		cout<<node<<" ";
		vis[node]=true;
		for(auto x:adj[node]){
			if(!vis[x]){
				dfs_Util(x, vis);
			}
		}
	}

	void dfs(int node){
		bool *vis=new bool[V];
		// vector<bool> vis;
		// map<int, bool> *vis;
		for (int i = 0; i < V; i++) 
        	vis[i] = false; 

		dfs_Util(node,vis);
	}


};

int main(){
	Graph g(5);
	g.addEdge(1, 0); 
    g.addEdge(0, 2); 
    g.addEdge(2, 1); 
    g.addEdge(0, 3); 
    g.addEdge(3, 4); 
   

	// // // print Graph list
	// g.printAdjList(0);

	// //BFS TRAVERSAL
	g.dfs(0);

	return 0;
}







