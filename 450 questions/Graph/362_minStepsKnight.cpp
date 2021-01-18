#include <iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<stack>
#include<map>
using namespace std; 

bool isInside(int x, int y, int N) 
{ 
    if (x >= 1 && x <= N && y >= 1 && y <= N) 
        return true; 
    return false; 
} 
  

int solve(int x, int y, int ox, int oy, int N){

	bool mat[N][N];
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			/* code */
			mat[i][j]=false;
		}
	}

	int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 }; 
    int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 }; 

	queue<pair<int, pair<int, int> > > q;
	q.push(make_pair(0,make_pair(x, y)));
	while(!q.empty()){
		int xa=q.front().second.first;
		int ya=q.front().second.second;
		int dist=q.front().first;
		q.pop();
		if(xa==ox && ya==oy) return dist;
		for (int i = 0; i < 8; i++) { 
            x = xa + dx[i]; 
            y = ya + dy[i]; 
  
            // If reachable state is not yet visited and 
            // inside board, push that state into queue 
            if (isInside(x, y, N) && !mat[x][y]) { 
                mat[x][y] = true; 

                q.push(make_pair(dist+1, make_pair(x, y))); 
            } 
        } 	
	}

}

void minStepToReachTarget(int knightPos[], int targetPos[], int N){
	

	cout<<solve(knightPos[0], knightPos[1], targetPos[0], targetPos[1], N);
	return;
}


int main(){
	int N = 30; 
    int knightPos[] = { 1, 1 }; 
    int targetPos[] = { 30, 30 }; 
    minStepToReachTarget(knightPos, targetPos, N); 
	return 0;
}







