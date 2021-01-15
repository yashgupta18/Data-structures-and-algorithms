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
#include <list> 

using namespace std;
// https://iq.opengenus.org/tarjans-algorithm/
#define V 5


int minKey(int key[], bool vis[]){
  int min=INT_MAX, index=-1;

  for (int i = 0; i < V; ++i)
  {
    /* code */
    if(vis[i]==false && key[i]<min){
      min=key[i];
      index=i;
    }
  }
  return index;
}

void printMST(int graph[V][V], int parent[]){
  for (int i = 1; i < V; ++i)
  {
    /* code */
    cout<<parent[i]<<"-"<<i<<" "<<graph[i][parent[i]];
    cout<<endl;
  }
}

void prim(int graph[V][V]){

  bool vis[V];
  int parent[V];
  int key[V];
  for (int i = 0; i < V; ++i)
  {
    /* code */
    vis[i]=false;
    key[i]=INT_MAX;
  }
  parent[0]=-1;
  key[0]=0;

  for (int i = 0; i < V-1; ++i)
  {
    /* code */
    int u=minKey(key, vis);
    vis[u]=true;
    for (int v = 0; v < V; ++v)
    {
      /* code */
      if(graph[u][v]!=0 && vis[v]==false && graph[u][v]<key[v]){
        parent[v]=u;
        key[v]=graph[u][v];
      }
    }
  }

  printMST(graph, parent);

} 


int main() {
  int graph[V][V] = { { 0, 2, 0, 6, 0 },  
                        { 2, 0, 3, 8, 5 },  
                        { 0, 3, 0, 0, 7 },  
                        { 6, 8, 0, 0, 9 },  
                        { 0, 5, 7, 9, 0 } };  
  prim(graph); 

  return 0;                  
}






