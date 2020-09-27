#include<iostream>
using namespace std;
#define V 4

void print_Colors(int colors[V]){
	for (int i = 0; i < V; ++i)
	{
		cout<<colors[i]<<"  ";
	}
}

bool isSafe(bool graph[V][V], int colors[V], int v, int c){
	//c is current value of c in for loop
	for (int i = 0; i < V; ++i)
	{
		//check if adjacent dont have same color
		if(graph[v][i] && c==colors[i]){
			return false;
		}
	}
	return true;
}

bool graphColoring_Util(bool graph[V][V], int colors[V],int m, int v){
	//if all vertices are visited
	if(v==V) return true;

	// for each color check if a vertex can have color c
	for (int c = 1; c <= m; ++c)
	{
		//check if color is different than adjacent vertices
		if(isSafe(graph, colors,v,c)){
			//if true store color for vertex v in colors array at index v
			colors[v]=c;

			//go for next vertex
			if(graphColoring_Util(graph, colors, m, v+1)==true){
				return true;
			}
			//if not true go for next vertex and set color array back to 0
			//backtracking
			colors[v]=0;
		}
	}
	return false;
}


void graphColoring(bool graph[V][V], int m){

	int colors[V];
	for (int i = 0; i < V; ++i)
	{
		colors[i]=0;
	}
	
	if(graphColoring_Util(graph, colors,m ,0)==true){
		cout<<"Solution exists"<<endl;
		print_Colors(colors);
		return;
	}
	cout<<"Solution do not exist";
	return;
}




int main() 
{ 
    /* Create following graph and test  
       whether it is 3 colorable 
      (3)---(2) 
       |   / | 
       |  /  | 
       | /   | 
      (0)---(1) 
    */
    bool graph[V][V] = { 
        { 0, 1, 1, 1 }, 
        { 1, 0, 1, 0 }, 
        { 1, 1, 0, 1 }, 
        { 1, 0, 1, 0 }, 
    }; 
    int m = 3; // Number of colors 
    graphColoring(graph, m); 
    return 0; 
} 