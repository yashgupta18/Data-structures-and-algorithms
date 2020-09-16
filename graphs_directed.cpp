#include<iostream>
#include<map>
#include<list>
#include<unordered_map>
#include<queue>
// #define V 5
using namespace std;
class Graph{

    //for directed graphs
    //Basic Structure 
    // A=(B,20), (C,15), (D,10)
    unordered_map<string, list<pair<string,int> > > adj;


public:
	//directed
	void addEdge(string x, string y, bool bidir, int wt){
		adj[x].push_back(make_pair(y,wt));
		if(bidir){
			adj[y].push_back(make_pair(x,wt));
		}
	}

	void printAdjList(){
		for(auto p: adj){
			string node=p.first;
			list<pair<string, int> > nbrs=p.second;

			cout<<node;
			for(auto nbr:nbrs){
				string dest=nbr.first;
				int dist=nbr.second;

				cout<<"->"<<dest<<" " << dist<< " ";
			}
			cout<<endl;
		}
	}

};

int main(){
	Graph g;
	g.addEdge("A","B",true, 5);
	g.addEdge("B","D",true, 25);
	g.addEdge("B","C",true, 20);
	g.addEdge("C","A",false, 15);
	g.addEdge("D","C",true, 10);
	g.addEdge("D","A",false, 30);

	// // print Graph list
	g.printAdjList();

	//BFS TRAVERSAL
	// g.bfs(0);


	return 0;
}


