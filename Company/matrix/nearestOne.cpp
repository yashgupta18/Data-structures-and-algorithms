#include <iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std; 
#define R 3 
#define C 3 
 
bool isvalid(int i,int j)
    {
        if(i==R||j==C||j<0||i<0)
            return false;
        return true;
    }

int main() 
// https://leetcode.com/problems/01-matrix/
{ 
    int mat[R][C] = 
    { 
        0,0,0,
 		0,1,0,
 		1,1,1
    }; 

    // vector<vector<int> > dir=
    int dir[4][4]={{1,0},{0,1},{0,-1},{-1,0}};
    queue<pair<int, int> > q;
  	
  	// bool vis[R][C];
  	// memset(dist, false, sizeof(dist));
  	int dist[R][C];
  	memset(dist, -1, sizeof(dist));
  	for (int i = 0; i < R; ++i)
  	{
  		for (int j = 0; j < C; ++j)
  		{
  			if(mat[i][j]==0){
  				// vis[i][j]=1;
  				q.push(make_pair(i,j));
  				dist[i][j]=0;
  			}
  		}
  	}	

  	while(!q.empty()){
		int f=q.front().first;
		int s=q.front().second;
		q.pop();


		for(auto x:dir){
			int a=f+x[0];
			int b=s+x[1];
			if(isvalid(a,b) && dist[a][b]==-1)
			{

				q.push(make_pair(a,b));
				dist[a][b]=dist[f][s]+1;
				// vis[a][b]=true;
			}
		}
	}

	for (int i = 0; i < R; ++i)
  	{
  		for (int j = 0; j < C; ++j)
  		{
  			cout<<dist[i][j]<<" ";
  		}
  		cout<<endl;
  	}	
  
    return 0; 
}





