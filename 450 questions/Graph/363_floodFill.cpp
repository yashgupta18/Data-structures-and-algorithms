#include <iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<stack>
#include<map>
using namespace std; 
#define M 8

#define N 8
bool isInside(int x, int y) 
{ 
    if (x >= 0 && x <= M && y >= 0 && y <= N) 
        return true; 
    return false; 
} 
  


void bfs(int screen[M][N], int x, int y, int newCol, int old){
	queue<pair<int,int > > q;
	q.push(make_pair(x,y));
	int dx[] = { 1, 1, 0, -1, 0, -1, -1, 1 }; 
    int dy[] = { 1, 0, 1, -1, -1, 0, 1, -1 }; 
	while(!q.empty()){
		int newx=q.front().first;
		int newy=q.front().second;
		screen[newx][newy]=newCol;

		q.pop();
		for (int i = 0; i < 8; ++i)
		{
			int r=newx+dx[i];
			int s=newy+dy[i];
			if(screen[r][s]==old && isInside(r, s)){
				q.push(make_pair(r, s));
			}
		}
		
	}
	for (int i = 0; i < M; ++i)
    {
    	for (int j = 0; j < N; ++j)
    	{
    		cout<<screen[i][j]<<" ";
    	}
    	cout<<endl;
    }
}


int main(){
	int screen[M][N] = {{1, 1, 1, 1, 1, 1, 1, 1},
               		{1, 1, 1, 1, 1, 1, 0, 0},
               		{1, 0, 0, 1, 1, 0, 1, 1},
               		{1, 2, 2, 2, 2, 0, 1, 0},
               		{1, 1, 1, 2, 2, 0, 1, 0},
               		{1, 1, 1, 2, 2, 2, 2, 0},
	               	{1, 1, 1, 1, 1, 2, 1, 1},
	               	{1, 1, 1, 1, 1, 2, 2, 1},
               	};

    int x=4, y=4, newCol=3;
    bfs(screen, x, y, newCol, screen[x][y]); 

    
	return 0;
}







