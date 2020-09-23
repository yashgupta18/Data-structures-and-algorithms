#include<iostream>

using namespace std;
#define N 4 


void print_Board(int board[N][N]){
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout<<board[i][j]<<"  ";
		}
		cout<<endl;
	}
}

bool isSafe(int board[N][N], int row, int col){
	int i, j; 
  
    /* Check this row on left side */
    for (i = 0; i < col; i++) 
        if (board[row][i]) 
            return false; 
  
    /* Check upper diagonal on left side */
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) 
        if (board[i][j]) 
            return false; 
  
    /* Check lower diagonal on left side */
    for (i = row, j = col; j >= 0 && i < N; i++, j--) 
        if (board[i][j]) 
            return false; 
  
    return true; 
}


bool solveNqueens(int board[N][N], int col){

	if(col>=N) return true;

	for (int row = 0; row < N; ++row)
	{
		
		if(isSafe(board, row, col)){
			board[row][col]=1;
			
			//recursion
			if(solveNqueens(board, col+1)){
				return true;
			}

			//backtrack
			board[row][col]=0;
		}
	}	

	return false;
}

int solve(){
	int board[N][N] = { { 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0 } }; 
		
	if(solveNqueens(board,0)== false){
		cout<<"No solution";
		return false;
	}
	print_Board(board);
	return true;
}



int main(){
	solve();
	return 0;
}