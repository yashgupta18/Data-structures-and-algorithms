#include <iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<stack>
#include<map>
using namespace std; 
#define R 4
#define C 4

int isSafe(int maze[R][C], int i,int j){
	if(i<R && j<C && i>=0 && j>=0 && maze[i][j]==1){
		return true;
	}
	return false;
}

bool ratInMaze(int maze[R][C],int i, int j, int sol[R][C]){
	if(i==R-1 && j==C-1 && maze[i][j]==1){
		sol[i][j]=1;
		return true;
	} 

	if(isSafe(maze,i ,j)==true){
		sol[i][j]=1;
		
		if(ratInMaze(maze, i+1, j, sol)==true){
			return true;
		}
	
		if(ratInMaze(maze, i, j+1, sol)==true){
			return true;
		}
		
		sol[i][j]=0;
		return false;
	}

	return false;
}

void printMaze(int maze[R][C]){
	for (int i = 0; i < R; ++i)
	{
		/* code */
		for (int j = 0; j < C; ++j)
		{
			/* code */
			cout<<maze[i][j]<<" ";
		}
		cout<<endl;
	}
}

bool solve(int maze[R][C]){
	int sol[R][C] = { { 0, 0, 0, 0 }, 
                    { 0, 0, 0, 0 }, 
                    { 0, 0, 0, 0 }, 
                    { 0, 0, 0, 0 } }; 
	if(ratInMaze(maze, 0, 0, sol)==true){
		printMaze(sol);
		return true;
	}else{
		cout<<"No solution";
		return false;
	};
}


int main(){
	int maze[R][C]={
					{1, 0, 0, 0},
					{1, 1, 0, 1},
					{0, 1, 0, 0},
					{1, 1, 1, 1}
				};

	solve(maze);
	return 0;
}







