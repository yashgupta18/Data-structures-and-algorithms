#include<iostream>
using namespace std;


const int ROW_COUNT = 6;
const int COL_COUNT = 6;
const int POSSIBLE_MOVES = 8;

int row_delta[POSSIBLE_MOVES] = {2, 1, -1, -2, -2, -1, 1, 2};
int col_delta[POSSIBLE_MOVES] = {-1, -2, -2, -1, 1, 2, 2, 1};

int board[ROW_COUNT][COL_COUNT];


void print_board() {
    for (int i = 0; i < ROW_COUNT; i++) {
        for (int j = 0; j < COL_COUNT; j++) {
            if (board[i][j] < 10)
                cout << ' ';
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
    cin.get();
}

void knightstour(int move, int row, int col){

	if(move==ROW_COUNT* COL_COUNT){
		print_board();
		return;
	}

	for (int i = 0; i < POSSIBLE_MOVES; ++i)
	{
		int new_row=row+row_delta[i];
		int new_col=col+col_delta[i];

		if(row<0 || row >= ROW_COUNT || col<0 || col>=COL_COUNT) continue;

		if(board[new_row][new_col]!=0) continue;

		board[new_row][new_col]=move+1;
		knightstour(move+1, new_row, new_col);
		board[new_row][new_col] = 0;
	}
}


void solve(int row, int col){
	for (int i = 0; i < ROW_COUNT; ++i)
	{
		for (int j = 0; j < COL_COUNT; ++j)
		{
			board[i][j]=0;
		}
	}
	board[row][col]=1;
	knightstour(1,row,col);
}




int main(){
	solve(2,3);
}