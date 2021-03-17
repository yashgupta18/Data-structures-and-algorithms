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


int main(){ 
    int parent[]={0, 1, 2, 3, 4, 5};
    int rank[]={0, 0, 0 , 0, 0 , 0};
  	unionSet(1, 2, parent, rank);
    unionSet(1, 3, parent, rank);
    unionSet(3, 4, parent, rank);
    // unionSet(3, 5, parent, rank);
    // unionSet(1, 5, parent, rank);
    cout<<find_set(4, parent); 
    cout<<find_set(4, parent); 
    cout<<find_set(4, parent); 
    return 0; 
    
}







