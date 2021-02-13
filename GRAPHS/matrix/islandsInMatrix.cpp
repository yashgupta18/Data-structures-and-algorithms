#include <iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<stack>
#include<map>
using namespace std; 
#define ROW 5
#define COL 5

// https://www.geeksforgeeks.org/find-number-of-islands/
// Find the number of islands
int isSafe(int x, int y, int mat[ROW][COL], bool visited[ROW][COL]){
	if(x>=0 && x<ROW && y>=0 && y<COL && !visited[x][y] && mat[x][y]==1) return 1;
	else return 0;
}

void dfs(int mat[ROW][COL], int i, int j, bool visited[ROW][COL]){

	static int X[] = { -1, -1, -1, 0, 0, 1, 1, 1 }; 
    static int Y[] = { -1, 0, 1, -1, 1, -1, 0, 1 }; 
    visited[i][j]=true;
	for (int k = 0; k < 8; ++k){
		// int r=i+X[k];
		// int c=j+Y[k];
		if(isSafe(i+X[k], j+Y[k] ,mat, visited)){
			dfs(mat, i+X[k], j+Y[k], visited);
		}

	}
	return;
}

int countIslands(int mat[ROW][COL]){
	int ans=0;
	bool visited[ROW][COL]; 
    memset(visited, 0, sizeof(visited)); 

	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COL; ++j)
		{
			if(mat[i][j]==1 && !visited[i][j]){
				dfs(mat, i, j, visited);
				ans++;
			}
		}
	}
	return ans;
}	




int main() 
{ 
    int M[][COL] = { { 1, 1, 0, 0, 0 }, 
                     { 0, 1, 0, 0, 1 }, 
                     { 1, 0, 0, 1, 1 }, 
                     { 0, 0, 0, 0, 0 }, 
                     { 1, 0, 1, 0, 1 } }; 
  
    cout << "Number of islands is: " << countIslands(M); 
  
    return 0; 
} 