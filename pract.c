#include<iostream>
using namespace std;
#define max 5

int main(){

	int a,b=2,c;
	a=2*(b++);
	c=2*(++b);

	cout<<a<<" "<<c;


	// int a,b;
	// a=b=4;
	// b=a++;

	// cout<<a++<<" "<<--b<<" "<<++a<<" ";

	// int b=15,c=5, d=8,e=8,a;
	// a=b>c ? c>d ? 12 : d>e ? 13 : 14 : 15;
	// cout<<a;

	// int c= --2;
	// printf("c=%d\n",c );

	// cout<<c; 
	// int i=10;
	// i=!i>14;
	// i=!i>14;
	// printf("i=%d\n", i);
	
	// int i=1,j=1;
	// for (i-- && j++; i < 10; i+=2)
	// {
	// 	cout<<"loop"<<endl;
	// }
	// printf("%d %d",i, i++);
	// cout<<i<<i++;
	// int a[5]={5,1,15,20,25};
	// i=++a[1];
	// j=a[1]++;
	// m=a[i++];
	// cout<<i<<j<<m;
	// i=max++;
	// printf("%d", i++);
	// solve(2,3);
}

// const int ROW_COUNT = 6;
// const int COL_COUNT = 6;
// const int POSSIBLE_MOVES = 8;

// int row_delta[POSSIBLE_MOVES] = {2, 1, -1, -2, -2, -1, 1, 2};
// int col_delta[POSSIBLE_MOVES] = {-1, -2, -2, -1, 1, 2, 2, 1};

// int board[ROW_COUNT][COL_COUNT];


// void print_board() {
//     for (int i = 0; i < ROW_COUNT; i++) {
//         for (int j = 0; j < COL_COUNT; j++) {
//             if (board[i][j] < 10)
//                 cout << ' ';
//             cout << board[i][j] << ' ';
//         }
//         cout << endl;
//     }
//     cin.get();
// }

// void knightstour(int move, int row, int col){

// 	if(move==ROW_COUNT* COL_COUNT){
// 		print_board();
// 		return;
// 	}

// 	for (int i = 0; i < POSSIBLE_MOVES; ++i)
// 	{
// 		int new_row=row+row_delta[i];
// 		int new_col=col+col_delta[i];

// 		if(row<0 || row >= ROW_COUNT || col<0 || col>=COL_COUNT) continue;

// 		if(board[new_row][new_col]!=0) continue;

// 		board[new_row][new_col]=move+1;
// 		knightstour(move+1, new_row, new_col);
// 		board[new_row][new_col] = 0;
// 	}
// }


// void solve(int row, int col){
// 	for (int i = 0; i < ROW_COUNT; ++i)
// 	{
// 		for (int j = 0; j < COL_COUNT; ++j)
// 		{
// 			board[i][j]=0;
// 		}
// 	}
// 	board[row][col]=1;
// 	knightstour(1,row,col);
// }



