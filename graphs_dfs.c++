#include <iostream>

#include <vector>
// #include<bits/stdc++.h>
using namespace std;
const int N=1e6+3;
vector<int> g[N];

bool vis[N];

void dfs(int u){
	vis[u]=true;
	for(int v:g[u]){
		if(vis[v])
			continue;
		dfs(v);
	}
}

int main()
{
	int u,v,n,m;
	//n->nodes, m->edges, u-v -> if u has edge from u to v
	cout<<"Enter number of nodes and edges:";
	cin>>n>>m;
	while(m--)
	{
		// cout<<"Enter edge:";
		cin>>u>>v ; 
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(4);
	if(vis[5]) cout<<"Reached";
	else cout<<"OOPS";
	return 0;
}	

/*

1 2
3 1
2 6
2 3
4 5
**/
