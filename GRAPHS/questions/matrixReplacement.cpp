#include <iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<stack>
#include<map>
using namespace std; 

// https://www.geeksforgeeks.org/given-matrix-o-x-replace-o-x-surrounded-x/

// Q Given a matrix where every element is either ‘O’ or ‘X’, replace ‘O’ with ‘X’ if surrounded 
// by ‘X’. A ‘O’ (or a set of ‘O’) is considered to be by surrounded by ‘X’ if there are ‘X’ at 
// locations just below, just above, just left and just right of it. 

#define ROW 6
#define COL 6


void floodFill(int i, int j, char prev, char newChar, char mat[ROW][COL]){
	if(i<0 || i>=ROW || j<0 || j>=COL) return;

	if(mat[i][j]!=prev) return;

	mat[i][j]=newChar;

	floodFill(i+1, j, prev, newChar,mat);
	floodFill(i-1, j, prev, newChar,mat);
	floodFill(i, j+1, prev, newChar,mat);
	floodFill(i, j-1, prev, newChar,mat);

}

void replaceMatrix(char mat[ROW][COL]){
	//convert all 'O' to '-' 
	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COL; ++j)
		{
			if(mat[i][j]=='O'){
				mat[i][j]='-';
			}
		}
	}

	//check all 4 edges if there are any '-'. if yes use floodfill algo to convert them back to 'O' as they are useless
	for (int i = 0; i < ROW; ++i)
	{
		if(mat[i][0]=='-'){
			floodFill(i,0, '-','O', mat);
		}
	}

	for (int i = 0; i < ROW; ++i)
	{
		if(mat[i][COL-1]=='-'){
			floodFill(i,COL-1, '-','O', mat);
		}
	}

	for (int i = 0; i < COL; ++i)
	{
		if(mat[0][i]=='-'){
			floodFill(0,i, '-','O', mat);
		}
	}

	for (int i = 0; i < COL; ++i)
	{
		if(mat[ROW-1][i]=='-'){
			floodFill(ROW-1,i, '-','O', mat);
		}
	}
}




int main()
{
   	char mat[ROW][COL] =  {
   						{'X', 'O', 'X', 'X', 'X', 'X'},
                     	{'X', 'O', 'X', 'X', 'O', 'X'},
                     	{'X', 'X', 'X', 'O', 'O', 'X'},
                     	{'O', 'X', 'X', 'X', 'X', 'X'},
                     	{'X', 'X', 'X', 'O', 'X', 'O'},
                     	{'O', 'O', 'X', 'O', 'O', 'O'},
                    };
 	
   
    replaceMatrix(mat);

    //convert the remaining '-' to 'X' and print the matrix
 	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COL; ++j)
		{
			if(mat[i][j]=='-'){
				mat[i][j]='X';
			}
			cout<<mat[i][j]<<" ";
			
		}
		cout<<endl;
	}
 
    return 0;
}