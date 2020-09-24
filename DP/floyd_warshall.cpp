#include<iostream>
using namespace std;

#define N 4
#define INF 99999  



void printSol(int mat[N][N]){
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if(mat[i][j]==INF){
				cout<<"INF"<<" ";
			}
			else
				cout<<mat[i][j]<<"  ";
		}

		cout<<endl;
	}
}

void floydWarshall(int mat[N][N]){

	int sol[N][N];
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			sol[i][j]=mat[i][j];
		}
	}


	for (int k = 0; k < N; ++k)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				//check if path exist from vertex i->k->j for each vertex
				if(sol[i][k]+sol[k][j]< sol[i][j] ){

					sol[i][j]=sol[i][k]+sol[k][j];
				}
			}
		}
	}
	printSol(sol);


}




int main()  
{  
    /* Let us create the following weighted graph  
            10  
    (0)------->(3)  
        |     /|\  
    5 |     |  
        |     | 1  
    \|/     |  
    (1)------->(2)  
            3     */
    int graph[N][N] = { {0, 5, INF, 10},  
                        {INF, 0, 3, INF},  
                        {INF, INF, 0, 1},  
                        {INF, INF, INF, 0}  
                    };  
  
    // Print the solution  
    floydWarshall(graph);  
    return 0;  
}