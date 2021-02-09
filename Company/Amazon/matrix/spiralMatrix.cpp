#include <iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std; 
#define R 3
#define C 6
 
void spiralMatrix(int matrix[R][C], int RS, int CS, int RE,int CE){
	if(RS>=RE || CS>=CE) return;

	for (int i = CS; i < CE; ++i)
	{
		cout<<matrix[RS][i]<<" ";
	}
	cout<<endl;

	for (int i = RS+1; i < RE; ++i)
	{
		cout<<matrix[i][CE-1]<<" ";
	}
	cout<<endl;
	if(RS+1!=RE){
		for (int i = CE-2; i >= CS; --i)
		{
			cout<<matrix[RE-1][i]<<" ";
		}
	}
	cout<<endl;
	
	if(CS+1!=CE){
		for (int i = RE-2; i > RS; --i)
		{
			cout<<matrix[i][CS]<<" ";
		}
	}
	
	cout<<endl;

	spiralMatrix(matrix, RS+1, CS+1, RE-1, CE-1);

}	


int main(){
	 int matrix[R][C] = { 
	 					{ 1, 2, 3, 4, 5, 6 },
                   		{ 7, 8, 9, 10, 11, 12 },
                    	{ 13, 14, 15, 16, 17, 18 } 
                    	};
	int n=sizeof(matrix)/sizeof(matrix[0]);
	spiralMatrix(matrix, 0,0,R,C);
	// cout<<ans;
	return 0;
}