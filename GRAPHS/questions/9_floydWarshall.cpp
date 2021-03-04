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
#define V 4
#define E 5
using namespace std; 

// void addEdge(vector<int> adj[], int u, int v, bool directed=false){ 
//     adj[u].push_back(v);
// 		if(!directed){
// 			adj[v].push_back(u);
// 		}	
// } 

// void printAdjList(vector<int> adj[]){
// 	for(int i=0; i<V; i++){
// 		cout<<i<<" ";
// 		for(auto x:adj[i]){
// 			cout<<"->"<<x;
// 		}
// 		cout<<endl;
// 	}
// }



// void bellman(int graph[V][V]){
//   for (int k = 0; k < E; ++k)
//   {
//     /* code */
//     for (int i = 0; i < V; ++i)
//     {
//       for (int j = 0; j <V ; ++j)
//       {
//         if(graph[i][k]+graph[k][j]<graph[i][j]){
//           graph[i][j]=graph[i][k]+graph[k][j];
//         }
//       }
//     }
//   }
// 	return;
// }




int main(){ 
    int graph[V][V] = { {   0,     13,   2,       INT_MAX }, 
                        { INT_MAX, 0, INT_MAX,     6}, 
                        { INT_MAX, 10,  0,         4}, 
                        { INT_MAX,INT_MAX, INT_MAX, 0}, 
                    };                        
  	
  	
  	cout<<"BEFORE"<<endl;
  	for (int i = 0; i < V; ++i)
  	{
      for (int j = 0; j <V ; ++j)
      {
        cout<<graph[i][j]<<"\t";
      }
  		
  		cout<<endl;
  	}
  	cout<<endl;
    for (int k = 0; k < V; ++k)
    {
    /* code */
      for (int i = 0; i < V; ++i)
      {
        for (int j = 0; j <V ; ++j)
        {
          if(graph[i][k]+graph[k][j]<graph[i][j] && graph[i][k]!=INT_MAX && graph[k][j]!=INT_MAX){
            graph[i][j]=graph[i][k]+graph[k][j];
          }
        }
      }
    
    }
  	cout<<"AFTER"<<endl;
  	for (int i = 0; i < V; ++i)
    {
      for (int j = 0; j <V ; ++j)
      {
        cout<<graph[i][j]<<"\t";
      }
      
      cout<<endl;
    }
  	
    return 0; 
}







