#include<iostream>
#include<map>
#include<string>
#include<stack>
#include<list>
#include<unordered_map>
#include<queue>

using namespace std;

class Edge
{
public:
	int source;
	int dest;
	int weight;
};


bool compare(Edge e1, Edge e2){
	// if e1<e2 return 1 else it needs rearrangement
	return e1.weight< e2.weight;
}

int findParent(int v, int *parent){
	if(parent[v]==v){
		return v;
	}
	return findParent(parent[v], parent);
}

void kruskals(Edge *input, int n, int E){

	//sort the input array as we pick the min edge
	sort(input, input+E, compare);

	Edge *output= new Edge[n-1];

	//create parent array
	int *parent= new int[n];

	for (int i = 0; i < n; ++i)
	{
		//initially each vertex is its own parent
		parent[i]=i;
	}

	int count=0;
	int i=0;
	while(count!=n-1){
		Edge currentEdge = input[i];

		//check for cycle
		int sourceParent = findParent(currentEdge.source, parent);
		int destParent= findParent(currentEdge.dest, parent);

		//if diff parents add edge to ouput
		if(sourceParent!=destParent){
			output[count]=currentEdge;
			count++;
			parent[sourceParent]=destParent;
		}
		i++;
	}

	for (int i = 0; i < n-1; ++i){
		if(output[i].source < output[i].dest){
		cout<<output[i].source<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
		}
		else{
			cout<<output[i].dest<<" "<<output[i].source<<" "<<output[i].weight<<endl;

		}
	}

}


int main(){

	int n,E;
	cin>>n>>E;
	Edge *input= new Edge[E];

	for (int i = 0; i < E; ++i)
	{
		int s,d,w;
		cin>>s>>d>>w;

		//each input[i] has 3 objects 
		input[i].source=s;
		input[i].dest=d;
		input[i].weight=w;
	}

	cout<<endl<<"Kruskals:"<<endl;
	kruskals(input,n,E);

	return 0;
}




//input
// 6 11
// 0 1 2
// 1 3 1
// 0 2 4
// 2 4 9
// 4 5 5
// 3 5 7
// 4 3 11
// 2 5 10
// 0 3 3
// 2 1 8
// 2 3 6
