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
#define V 10
// #define E 8
using namespace std; 

void addEdge(vector<int> adj[V], int u, int v, bool directed=false){ 
    adj[u].push_back(v);
		if(!directed){
			adj[v].push_back(u);
		}	
} 

void printAdjList(vector<int> adj[]){
	for(int i=1; i<V; i++){
		cout<<i<<" ";
		for(auto x:adj[i]){
			cout<<"->"<<x;
		}
		cout<<endl;
	}
}


void dfsUtil(vector<int> adj2[], int v, bool vis[V]){
  vis[v]=true;
  for(auto i:adj2[v]){
    if(vis[i]==false){
      dfsUtil(adj2, i, vis);
    }
  }
  cout<<v<<" ";
}

// vector<int> reverseGraph(vector<int> adj[V]){
//   vector<int> adj2[V];
//   for (int i = 0; i < V; ++i)
//   {
//     for(auto k:adj[i]){
//       adj2[k].push_back(i);
//     }
//   }
//   return adj2;
// }


void dfs(vector<int> adj[], int v, bool vis[V], stack<int> &s){
  vis[v]=true;
  for(auto i:adj[v]){
    if(vis[i]==false){
      dfs(adj, i, vis, s);
    }
  }
  //add to stack
  s.push(v);
  // cout<<s.top()<<" ";
}

void kosaraju(vector<int> adj[]){
  bool *vis = new bool[V];
  stack<int> s;
  for (int i = 1; i < V; ++i)
  {
    vis[i]=false;
  }

  // fisrt DFS Call. 
  for (int i = 0; i < V; ++i)
  {
    if(vis[i]==false){
      dfs(adj,i, vis,s);
    }
  }

  // transpose/reverse graph
  vector<int> adj2[V];

  for (int i = 1; i < V; ++i)
  {
    for(auto k:adj[i]){
      adj2[k].push_back(i);
    }
  }

  // printAdjList(adj2);

  for (int i = 1; i < V; ++i)
  {
    vis[i]=false;
  }

  while(!s.empty()){
    int t=s.top();
    s.pop();
    if(vis[t]==false){
    dfsUtil(adj2, t, vis);
    cout<<endl;
  }
}
}




int main() { 

  	vector<int> adj[V];
    addEdge(adj, 1, 2, true);
    addEdge(adj, 2, 3, true);
    addEdge(adj, 3, 1, true);
    addEdge(adj, 3, 4, true);
    addEdge(adj, 4, 5, true);
    addEdge(adj, 5, 4, true);
    addEdge(adj, 5, 6, true);
    addEdge(adj, 6, 7, true);
    addEdge(adj, 7, 8, true);
    addEdge(adj, 7, 10, true);
    addEdge(adj, 8, 9, true);
    addEdge(adj, 9, 6, true);

    // printAdjList(adj);
    cout<<"Connected Components are:";
    kosaraju(adj);
    
  	
    return 0; 
}








