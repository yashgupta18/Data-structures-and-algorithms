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
    return find_set(parent[u], parent);
  }
}

int unionSet(int u, int v, int parent[]){
  int u_set=find_set(u, parent);
  int v_set=find_set(v, parent);

  if(u_set!=v_set){
    parent[v_set]=u_set;
  }
}


int main(){ 
    int parent[]={0, 1, 2, 3, 4, 5};
  	unionSet(1, 2, parent);
    unionSet(3, 4, parent);
    unionSet(0, 5, parent);
    unionSet(3, 5, parent);
    unionSet(1, 5, parent);
    cout<<find_set(3, parent); 
    return 0; 
    
}







