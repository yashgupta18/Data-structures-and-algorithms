#include<iostream>
#include<map>
#include<list>
#include<queue>

using namespace std;

class Graph{
	map<int, list<int> > l;
	// vector<int,vector<int,int>> v;
public:
	void addEdge(int x, int y){
		l[x].push_back(y);
		l[y].push_back(x);
	}

	void bfs(int node){
		map<int, int> visited;
		queue<int>q;

		q.push(node);
		visited[node]=true;

		while(!q.empty()){
			int adjnode = q.front();
			q.pop();
			cout<<adjnode<<" "<<endl;

			for (int i:l[adjnode])
			{
				if(!visited[i])
					q.push(i);
					visited[i]=true;

			}
		}
	}
	
};

int main(){
	Graph g;
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(4,5);

	g.bfs(0);

	return 0;
}


/*

1 2
3 1
2 6
2 3
4 5
// **/