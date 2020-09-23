#include<iostream>
#define V 5 

using namespace std;

int minWeight(int new_weight[V], bool visited[V]){
	int min=INT_MAX, minIndex;

	for (int i = 0; i < V; ++i)
	{
		if(visited[i]==false && new_weight[i]<min){
			min=new_weight[i];
			minIndex=i;
		}
	}

	return minIndex;
}


void printMST(int parent[V], int graph[V][V]){
	for (int i = 1; i < V; ++i)
	{
		cout<<"Edge="<<i<<"-"<<parent[i]<<"  "<<"Weight="<<graph[i][parent[i]]<<endl;
	}
}


void primMST(int graph[V][V]){
	//final mst stored here
	int parent[V];

	//weight minimum
	int new_weight[V];

	//selected in mst or not
	bool visited[V];

	for (int i = 0; i < V; ++i)
	{
		new_weight[i]=INT_MAX;
		visited[i]=false;
	}

	new_weight[0]=0;	//wt of path of root node is 0
	parent[0]=-1; //first is always root

	for (int i = 0; i < V; ++i)
	{
		//select minimum neighbour of vertex path vertex for neigh
		int u=minWeight(new_weight, visited);

		visited[u]=true;
		for (int j = 0; j < V; ++j)
		{
			//if graph[i][j] is non-zero, visited is false meaning not yet selected in mstt, and weight in matrix is less than in new_weight array
			if(graph[i][j] && visited[j]==false && graph[i][j]<new_weight[j]){
				//update parent(added to MST)
				parent[j]=i;

				//update weight
				new_weight[j]=graph[i][j];
			}
		}
	}

	printMST(parent, graph);
}



int main(){
	int graph[V][V] = { { 0, 2, 0, 6, 0 }, 
                        { 2, 0, 3, 8, 5 }, 
                        { 0, 3, 0, 0, 7 }, 
                        { 6, 8, 0, 0, 9 }, 
                        { 0, 5, 7, 9, 0 } }; 
 
    // Print the solution 
    primMST(graph); 
	



	return 0;
}