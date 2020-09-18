#include<iostream>
#include<map>
#include<string>
#include<stack>
#include<list>
#include<unordered_map>
#include<queue>
// #define V 5
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

	void addEdge(int x, int y, bool directed=false){
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

	void bfs(int node){
		bool vis[]={};
		// vector<bool> vis;
		// map<T, int> vis;
		queue<int>q;

		q.push(node);
		vis[node]=true;

		while(!q.empty()){
			int node = q.front();
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


	bool containscycle_Util(int node, bool vis[], int parent){
		vis[node]=true;

		for(auto i:adj[node]){
			if(!vis[i]){
				//if not visited recursive fn is called again
				if(containscycle_Util(i,vis,node)){
					return true;
				}
			}
			//if vis[] is true then check if i is parent. if not there is a cycle
			else if(i!=parent){
				return true;
			}
		}
		return false;

	}

	bool containscycle(){
		bool *vis = new bool[V]; 
    	for (int i = 0; i < V; i++) 
       		vis[i] = false; 
		
		for(int i=0; i<V; i++){
			if(!vis[i]){
				//for each in vis check for cycle using DFS
				if(containscycle_Util(0,vis,-1)){
					return true;
				}
			}
		}
		return false; 
	}


	bool directedCycle_Util(int node,bool vis[], bool helper[]){
		vis[node]=true;
		helper[node]=true;

		for(auto i:adj[node]){
			if(!vis[node] && directedCycle_Util(i,vis,helper)){
				return true;
			}
			else if(helper[node]==true) return true;
		}
		//turn helper[i] as false to return recursive fn
		helper[node]=false;
		return false;
	}

	bool directedCycle(){
		bool *vis=new bool[V];
		bool *helper=new bool[V];

		for (int i = 0; i < V; ++i)
		{
			vis[i]=false;
			helper[i]=false;
		}

		for(int i=0; i<V; i++){
			if(!vis[i]){
				if(directedCycle_Util(i,vis, helper)){
					return true;
				}
			}
		}
		return false;
	}
	
	void dfs_connected_components(int node, bool vis[]){
		vis[node]=true;

		for(auto i: adj[node]){
			if(!vis[i]){
				dfs_connected_components(i, vis);
			}
		}
	}

	void Dfs_Topological_Util(int node, bool vis[],stack<int> &s){
		// cout<<node<<" ";
		vis[node]=true;
		for(auto x:adj[node]){
			if(!vis[x]){
				// cout<<x<<" ";
				Dfs_Topological_Util(x, vis,s);
			}
		}
		s.push(node);
	}

	void Dfs_Topological(){
		stack<int> s;
		bool *vis=new bool[V];
		// vector<bool> vis;
		// map<int, bool> *vis;
		for (int i = 0; i < V; i++){
        	vis[i] = false; 
        }

        for (int i = 0; i < V; ++i)
        {
        	if(vis[i]==false){
        		Dfs_Topological_Util(i,vis,s);
        	}
        }

		while (s.empty() == false) 
    	{ 
        	cout << s.top() << " "; 
        	s.pop(); 
    	} 
	}

	int min(int x, int y) 
	{ 
    	return (x < y)? x : y; 
	} 
	
		
};

int main(){
	Graph g(5);
	// Graph<int> g;
	g.addEdge(1, 0); 
    g.addEdge(0, 2); 
    g.addEdge(2, 1); 
    g.addEdge(0, 3); 
    g.addEdge(3, 4); 
   

	// // // // print Graph list
	// g.printAdjList(0);

	// // //BFS TRAVERSAL
	// g.bfs(0);

	// // DFS TRAVERSAL
	// g.dfs(0);


	// //Detect cycle for UNDIRECTED GRAPHS
	// Graph g2(8); 
 //    g2.addEdge(0, 1); 
 //    g2.addEdge(1, 2);
 //    g2.addEdge(2, 3); 
 //    g2.addEdge(3, 4);
 //    g2.addEdge(5, 6); 
 //    g2.addEdge(6, 7);

	// if(g2.containscycle()){
	// 	cout<<"Contains Cycle";
	// }else{
	// 	cout<<"NO Cycle";
	// }


	//Detect Cycle for DIRECTED GRAPH
	// if(g.directedCycle()){
	// 	cout<<"Contains Cycle";
	// }else{
	// 	cout<<"NO Cycle";
	// }


	// //connected components
	// Graph g3(12);
	// int s=12;
	// g3.addEdge(1, 2); 
 //    g3.addEdge(1, 4); 
 //    g3.addEdge(4, 3); 
 //    g3.addEdge(5, 6); 
 //    g3.addEdge(5, 7); 
 //    g3.addEdge(6, 8);
 //    g3.addEdge(9, 10); 
 //    g3.addEdge(9, 11); 
 
 //   	g3.printAdjList(1);

 //    int count=0;
 //    bool *vis=new bool[s];
 //    for(int i=1; i<s; i++){
 //    	if(!vis[i]){
 //    		count++;
 //    		g3.dfs_connected_components(i,vis);
 //    	}
 //    }
 //    cout<<"Count: "<<count;
	


    //TOPOLOGICAL SORTING- Works for Directed Acyclic graph
   	// Graph g4(6); 
    // g4.addEdge(5, 2); 
    // g4.addEdge(5, 0); 
    // g4.addEdge(4, 0); 
    // g4.addEdge(4, 1); 
    // g4.addEdge(2, 3); 
    // g4.addEdge(3, 1); 
    // // g3.printAdjList(0);

    // g4.Dfs_Topological();

    //Shortest path from source to destinantion in unweighted graph
    Graph g5(5);
    g5.addEdge(0, 1); 
    g5.addEdge( 0, 3); 
    g5.addEdge( 1, 2); 
   	g5.addEdge( 3, 4); 
    g5.addEdge( 3, 7); 
    g5.addEdge( 4, 5); 
    g5.addEdge( 4, 6); 
    g5.addEdge( 4, 7); 
    g5.addEdge( 5, 6); 
    g5.addEdge( 6, 7); 
    int source = 0, dest = 7; 
    g5.bfs_shortest(source,dest);
    



	return 0;
}


