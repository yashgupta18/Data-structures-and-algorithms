#include <iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<stack>
#include<map>
#include<string>
using namespace std; 
#define ROW 4
#define COL 5

// CHECK IF ALL CHARS OF WORD EXISTS IN MATRIX OR NOT. TRAVERSE UP,DOWN, LEFT,RIGHT. LEETCODE Q
	
bool dfs(char mat[ROW][COL], string &word, int i, int j, int index){
	//if index has reached till last index
	if(index==word.size()) return true;

	//i and j are out of bounds
	if(i<0 || i>=ROW || j<0 || j>=COL) return false;

	//current matrix element is not same as char at word->index
	if(mat[i][j]!=word[index]) return false;

	//temporarily change the matrix element
	mat[i][j]='*';

	//dfs on current element
	bool ans=dfs(mat, word, i+1, j, index+1) || dfs(mat, word, i-1, j, index+1) || dfs(mat, word, i, j-1, index+1) || dfs(mat, word, i, j+1, index+1);
	
	//backtrack to same element
	mat[i][j]=word[index];
	return ans;
}


bool searchWord(char mat[ROW][COL], string &word){
	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; i < COL; ++j)
		{
			if(dfs(mat, word, i, j, 0)){
				return true;
			}
			
		}
	}
	return false;
}



int main()
{
    char mat[ROW][COL] = {
    					{'A','B','C','E'},
    					{'S','F','C','S'},
    					{'A','D','E','E'}
    				};

  
   	string word="ABCCE";
   	cout<<searchWord(mat,word);
    return 0;
}












