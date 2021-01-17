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
const int MAX = 1e4 + 5;  

int id[MAX], nodes, edges;
pair <long long, pair<int, int> > p[MAX];


// void printMST(int graph[V][V], int parent[]){
//   for (int i = 1; i < V; ++i)
//   {
//      code 
//     cout<<parent[i]<<"-"<<i<<" "<<graph[i][parent[i]];
//     cout<<endl;
//   }
// }

int find_set(int u, int parent[]){
  if(u==parent[u]){
    return parent[u];
  }
  else{
    return parent[u]=find_set(parent[u], parent);
  }
}

void unionSet(int u, int v, int parent[], int rank[]){
  int u_set=find_set(u, parent);
  int v_set=find_set(v, parent);

  if(u_set!=v_set){
    parent[v_set]=u_set;
  }

  if(rank[u_set]<rank[v_set]){
    parent[u_set]=v_set;
  }
  else if(rank[v_set]<rank[u_set]){
    parent[v_set]=u_set;
  }else{
    // can be anything
    parent[v_set]=u_set;
  }
}

long long kruskalsAlgo(pair <long long, pair<int, int> > p[]){
  // for disjoint union oprn
  int parent[nodes], rank[nodes];
  for (int i = 0; i < nodes; ++i)
  {
    /* code */
    parent[i]=i;
    rank[i]=0;
  }

  int minCost=0;
  for (int i = 0; i < edges; ++i)
  {
    /* Get each node src dest , weight */
    int u=p[i].second.first;
    int v=p[i].second.second;
    int cost=p[i].first;

    // check if it doesnt make cycle
    if(find_set(u, parent)!=find_set(v, parent)){
      // add wt to min cost
      minCost=minCost+cost;
      // add parent of u to v
      unionSet(u, v, parent, rank);
    }
  }

  return minCost;

} 


int main() {
  // int graph[V][V] = { { 0, 2, 0, 6, 0 },  
  //                       { 2, 0, 3, 8, 5 },  
  //                       { 0, 3, 0, 0, 7 },  
  //                       { 6, 8, 0, 0, 9 },  
  //                       { 0, 5, 7, 9, 0 } };  
  int wt,src,dest; 
  cout<<"Input"<<endl;
  cin>>nodes>>edges;

  for (int i = 0; i < edges; ++i){
    cin>>wt>>src>>dest;
    //make pair 
    p[i]=make_pair(wt, make_pair(src, dest));
  } 
  //sort acc to weight
  sort(p, p+edges); 

  int minimumCost=kruskalsAlgo(p);
  cout<<minimumCost;

// input
// 5 7
// 2 0 1
// 6 0 3
// 3 1 2
// 8 1 3
// 5 1 4
// 9 4 3
// 7 2 4
  return 0;                  
}






