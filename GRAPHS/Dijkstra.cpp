#include<iostream>
#include<map>
#include<list>
#include<unordered_map>
#include<map>
#include<set>
#include<queue>
// #define V 5
using namespace std;
template<typename T>
class Graph{
    //Basic Structure 
    // A=(B,20), (C,15), (D,10)
    // structure cityA= (city B, distance), (city C, distance)
    unordered_map<T, list<pair<T,int> > > m;

    //for sorted cities
    // map<T, list<pair<T,int> > > m;


public:
	//directed
	void addEdge(T x, T y,int wt, bool bidir=true){
		m[x].push_back(make_pair(y,wt));
		if(bidir){
			m[y].push_back(make_pair(x,wt));
		}
	}

	void printAdjList(){
		//iterate over keys
		for(auto p: m){
			cout<<p.first<<"-> ";

			//iterate over list
			for(auto l:p.second){
				cout<<"("<<l.first<<" " << l.second<< ") ";
			}
			cout<<endl;
		}
	}


	void dijkstra(T src){

		// create a map dist(city, dist)
		unordered_map<T, int> dist;

		for(auto i: m){
			//all distances to infinity
			dist[i.first]=INT_MAX;
		} 

		//Make set to find node with minimum distance as first , city as second pair
		set<pair<int,T> > s;

		dist[src]=0;
		s.insert(make_pair(0, src));

		while(!s.empty()){

			//point to first in set
			auto p = *(s.begin());

			//node with minimum distance will always be first node in set
			int nodeDist=p.first;
			T node=p.second;
			//delete beginning node
			s.erase(s.begin());

			//iterate over nodes adjacent to current node using m
			for(auto adj:m[node]){

				// check if dist of src + node dist is less than dist
				if(nodeDist + adj.second < dist[adj.first]){
					//In Set, updation is not possible, so we remove the old pair and add th new pair
					T dest=adj.first;
					// 	auto f = i.find(make_pair(dist[dest], dest));
					auto f = s.find(make_pair(dist[dest], dest));
					// int f=
					if(f!=s.end()){
						s.erase(f);
					}

					//insert new pair
					dist[dest]=nodeDist + adj.second;
					s.insert(make_pair(dist[dest], dest));	
				}
			}
		}
			
		//print dist from all other nodes
		for(auto d:dist){
			cout<<d.first<<"-"<<d.second<<" ";
		}	
	}
};

int main(){
	Graph<string> g;
	g.addEdge("A","B", 5);
	g.addEdge("B","D",25);
	g.addEdge("B","C",20);
	g.addEdge("C","A", 15);
	g.addEdge("D","C",10);
	g.addEdge("D","A", 30);

	// // print Graph list
	// g.printAdjList();

	//BFS TRAVERSAL
	// g.bfs(0);

	g.dijkstra("A");
	//another solution
	// https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/
	return 0;
}


