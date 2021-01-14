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
#define V 8

int graph[V][V] = {
   {0, 0, 1, 0, 0, 0, 0, 0},
   {1, 0, 0, 0, 0, 0, 0, 0},
   {0, 1, 0, 1, 0, 0, 0, 0},
   {0, 0, 0, 0, 1, 0, 0, 0},
   {0, 0, 0, 0, 0, 1, 0, 0},
   {0, 0, 0, 0, 0, 0, 1, 0},
   {0, 0, 0, 0, 0, 0, 0, 1},
   {0, 0, 0, 0, 1, 0, 0, 0}
};

void dfs(int u, int disc[], int inTime[], stack<int>&s, bool inStack[]){
  s.push(u);
  inStack[u]=true;
  static int time=0;
  disc[u]=inTime[u]=++time;
  for (int v = 0; v < V; ++v)
  {
    /* code */
    if(graph[u][v]){
      //if not visited
      if(disc[v]==-1){
        dfs(v, disc, inTime, s, inStack);
        inTime[u]=min(inTime[v], inTime[u]);
      }
      //if already visited update current node inTime with discTime of visited
      else if(inStack[v]){
        inTime[u]=min(inTime[u], disc[v]);
      }
    }
  }

  int poppedItem=0;
  //if come back to initial node of SCC and inTime==discTime that's 1 SSC
  if(inTime[u]==disc[u]){
    while(s.top()!=u){
      // 1 SSC Start 
      int poppedItem=s.top();
      s.pop();
      inStack[poppedItem]=false;
      cout<<poppedItem<<" ";
    }
    poppedItem=s.top();
    s.pop();
    cout<<poppedItem<<" "<<endl;
    // 1 SSC End 
  }
}

void strongConComponent(){
  int disc[V];
  int inTime[V];
  bool inStack[V];
  stack<int> s;

  for (int i = 0; i < V; ++i)
  {
    /* code */
    disc[i]=-1;
    inTime[i]=-1;
    inStack[i]=false;
  }

  for (int i = 0; i < V; ++i)
  {
    /* code */
    if(disc[i]==-1){
      dfs(i, disc, inTime, s, inStack);
    }
  }
}

int main() {
  // EXPLAINATION
  // https://www.youtube.com/watch?v=EDb_TGBZqgg&ab_channel=CodeNCode

  // STEPS
  //dfs 
  //if already visited update with disc time
  // if discTime== inTime
  // pop stack till that element and keep popping. Thats 1 SSC
   strongConComponent();
}

