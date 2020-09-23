#include<iostream>

using namespace std;
#define N 4
bool rat_solve(int mat[N][N], int out[N][N], int i, int j);

void print_Maze(int out[N][N]){
	cout<<"Output maze path"<<endl;
	for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				cout<<out[i][j]<<"  ";
			}
			cout<<endl;
		}
	
}

bool isSafe(int x, int y, int mat[N][N]){
	if (x >= 0 && x < N && y >= 0 && y < N && mat[x][y] == 1){
		return true;
	}
	return false;
	
}

bool solve(int mat[N][N]){
	 int out[N][N] = { { 0, 0, 0, 0 }, 
                      { 0, 0, 0, 0 }, 
                      { 0, 0, 0, 0 }, 
                      { 0, 0, 0, 0 } };

	if (rat_solve(mat,out, 0, 0) == false){
		cout<<"Solution doesnt exist";
		return false;
	}
		
	print_Maze(out);
	return true;
}

bool rat_solve(int mat[N][N], int out[N][N], int i, int j){
	if(i==N-1 && j==N-1 && mat[i][j]==1){ 
		out[i][j]=1;
		return true;
	}

	if(isSafe(i,j, mat)==true){
		out[i][j]=1;
		if(rat_solve(mat,out, i+1,j)==true) return true;
		if(rat_solve(mat,out, i,j+1)==true) return true;

		out[i][j]=0;
		return false;
	}	
	return false;
}





int main(){


	 int mat[N][N] = { { 1, 0, 0, 0 }, 
                       { 1, 1, 0, 1 }, 
                       { 0, 1, 0, 0 }, 
                       { 1, 1, 1, 1 } }; 
    solve(mat); 
	return 0;	
}








