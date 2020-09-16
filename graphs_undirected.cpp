#include<iostream>
#include<map>
#include<list>
#include<unordered_map>
#include<queue>
// #define V 5
using namespace std;
template<typename T>
class Graph{
	// int V;  
 //    list<int> *adj;

   	map<T, list<T> > adj;
public:
	// Graph(int V){
	// 	this->V= V;
	// 	adj=new list<int>[V];
	// }


	void addEdge(int x, int y){
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	void printAdjList(int x){
		for(int i=0; i<adj.size(); i++){
			cout<<i<<" ";
			for(auto x:adj[i]){
				cout<<"->"<<x;
			}
			cout<<endl;
		}
	}

	void bfs(T node){
		// bool vis[V];
		map<T, int> vis;
		queue<int>q;

		q.push(node);
		vis[node]=true;

		while(!q.empty()){
			T node = q.front();
			q.pop();
			cout<<node<<" "<<endl;

			for (auto i:adj[node])
			{
				if(!vis[i])
					q.push(i);
					vis[i]=true;
			}
		}
	}

	void dfs_Util(T node, map<T, bool> &vis){
		cout<<node<<" ";
		vis[node]=true;
		for(auto x:adj[node]){
			if(!vis[x]){
				dfs_Util(x, vis);
			}
		}
	}

	void dfs(T node){
		map<T, bool> vis;
		//Mark all as false(not visited)
		for(auto p:adj){
			T node=p.first;
			vis[node]=false;
		}
		dfs_Util(node,vis);
	}

	
	
};

int main(){
	// Graph g(5);
	Graph<int> g;
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(4,5);
	g.addEdge(3,0);

	// // // // print Graph list
	// g.printAdjList(0);

	// // //BFS TRAVERSAL
	// g.bfs(0);

	// DFS TRAVERSAL
	g.dfs(0);

	return 0;
}


