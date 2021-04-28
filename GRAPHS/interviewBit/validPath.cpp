// https://www.interviewbit.com/problems/valid-path/
// There is a rectangle with left bottom as  (0, 0) and right up as (x, y). 
// There are N circles such that their centers are inside the rectangle.
// Radius of each circle is R. Now we need to find out if it is possible that we can move from (0, 0) 
// to (x, y) without touching any circle.

// Note : We can move from any cell to any of its 8 adjecent neighbours and we cannot move outside 
// the boundary of the rectangle at any point of time.


#include<iostream>
#include<map>
#include<string>
#include<stack>
#include<list>
#include<vector>
#include<queue>
using namespace std;

bool isSafe(int a, int b, vector<vector<int> > v, int x, int y){
    if(a>=0 && a<=x && b>=0 && b<=y && v[a][b]==0){
        return true;
    }
    return false;
}

string solve(int x, int y, int n, int r, vector<int> &E, vector<int> &F) {
    vector<vector<int> > v( x+1 , vector<int> (y+1, 0));
	// int v[x + 1][y + 1];
    bool visited[x + 1][y + 1];
    
    int xa[]={r, 0,-r, 0, -r, r, r, -r};
    int ya[]={0,r, 0,-r, -r, r, -r, r,};
    for(int i=0;i<n; i++){
        int p=E[i], q=F[i];
        if(p==x && q==y){
            return "NO";
        } 
        for(int j=0;j<8;j++){
            int np=p+xa[j], nq=q+ya[j];
            
            if(isSafe(np,nq,v, x,y)){
                v[np][nq]=-1;
            }
        }
    }

    queue<pair<int,int> > q;
	q.push(make_pair(0, 0));
    while(!q.empty())
    {
        // Dequeue the front element and check if c or boundary.
        int currx = q.front().first;
        int curry = q.front().second;
        q.pop();
        
        if(currx < 0 or curry < 0 or currx > x or curry > y or 
            visited[currx][curry] or v[currx][curry] == -1)
        {
            continue;
        }
        
        // Else, Add it's 8 neighbours to queue
        q.push(make_pair(currx + 1, curry));
        q.push(make_pair(currx - 1, curry));
        q.push(make_pair(currx, curry + 1));
        q.push(make_pair(currx, curry - 1));
        q.push(make_pair(currx + 1, curry + 1));
        q.push(make_pair(currx + 1, curry - 1));
        q.push(make_pair(currx - 1, curry + 1));
        q.push(make_pair(currx - 1, curry - 1));
        
        // Mark current point as visited
        visited[currx][curry] = true;
    }
    
    // Check if destination is visited
    if(visited[x][y])
    {
        return "YES";
    }
   return "NO";
}


int main(){

	vector<int> E, F;
	E.push_back(17);
	E.push_back(16);
	E.push_back(12);
	E.push_back(0);
	E.push_back(40);

	F.push_back(52);
	F.push_back(61);
	F.push_back(61);
	F.push_back(25);
	F.push_back(31);

	cout<<solve(41,67,5,0,E, F);

	return 0;
}
