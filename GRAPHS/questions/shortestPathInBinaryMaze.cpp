#include <iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<stack>
#include<map>
using namespace std; 
#define ROW 9
#define COL 10

// https://www.geeksforgeeks.org/shortest-path-in-a-binary-maze/

struct Point
{
    int x;
    int y;
};

struct QueueNode
{
	Point P;
	int d;
};

int isSafe(int x, int y, int mat[ROW][COL]){
	if(x>=0 && x<ROW && y>=0 && y<COL) return 1;
	else return 0;
}


int BFS(int mat[ROW][COL], Point source, Point dest){
	// make queue of struct QueueNode
	queue<QueueNode> q;
	QueueNode pt={source, 0};
	q.push(pt);

	//maintain a vis Matrix
	bool vis[ROW][COL];
	memset(vis, false, sizeof(vis));
	//make source vis
	vis[source.x][source.y]=true;
	
	//a pt can move in 4 directions
	int X[]={-1, 0, 1, 0};
	int Y[]={0, -1, 0, 1};
	
	while(!q.empty()){
		QueueNode curr=q.front();
		Point node=curr.P;

		//if curr node is destination return its dist from source
		if(node.x==dest.x && node.y==dest.y){
			return curr.d;
		}
		q.pop();

		//check and add all adjacent nodes to queue
		for (int i = 0; i < 4; ++i)
		{	
			int xNewCord=node.x+X[i];
			int yNewCord=node.y+Y[i];

			if(isSafe(xNewCord, yNewCord, mat) && !vis[xNewCord][yNewCord] && mat[xNewCord][yNewCord]){
				vis[xNewCord][yNewCord]=true;
				QueueNode newPt={ {xNewCord, yNewCord}, curr.d + 1};
				q.push(newPt);
			}
		}
	}

	//if no ans return -1
	return -1;
}	




int main()
{
    int mat[ROW][COL] =
    {
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
        { 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }
    };
 
    Point source = {0, 0};
    // int sourceX=0, sourceY=0;
    // int destX=3, destY=4;
    Point dest = {3, 4};
    int dist = BFS(mat, source, dest);
 
    if (dist != -1)
        cout << "Shortest Path is " << dist ;
    else
        cout << "Shortest Path doesn't exist";
 
    return 0;
}