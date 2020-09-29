#include<iostream>
using namespace std;
#define M 8
#define N 8


void floodFill_Util(int screen[M][N], int x, int y, int newC, int prevC){

	if(x<0 || x>=M || y<0 || x>=N) return;
	if(screen[x][y]!=prevC) return;
	if(screen[x][y]==newC) return;
	screen[x][y]=newC;

	floodFill_Util(screen,x, y+1, newC, prevC);
	floodFill_Util(screen,x-1, y, newC, prevC);
	floodFill_Util(screen,x, y-1, newC, prevC);
	floodFill_Util(screen,x+1, y, newC, prevC);
}


void floodFill(int screen[M][N],int x,int y,int newC){
	int prevC=screen[x][y];
	floodFill_Util(screen, x, y, newC, prevC);
}





int main() 
{ 
    int screen[M][N] = {{1, 1, 1, 1, 1, 1, 1, 1}, 
                      {1, 1, 1, 1, 1, 1, 0, 0}, 
                      {1, 0, 0, 1, 1, 0, 1, 1}, 
                      {1, 2, 2, 2, 2, 0, 1, 0}, 
                      {1, 1, 1, 2, 2, 0, 1, 0}, 
                      {1, 1, 1, 2, 2, 2, 2, 0}, 
                      {1, 1, 1, 1, 1, 2, 1, 1}, 
                      {1, 1, 1, 1, 1, 2, 2, 1}, 
                     }; 
    int x = 4, y = 4, newC = 3; 
    floodFill(screen, x, y, newC); 
  	
    cout << "Updated screen after call to floodFill: \n"; 
    for (int i=0; i<M; i++) 
    { 
        for (int j=0; j<N; j++) 
           cout << screen[i][j] << " "; 
        cout << endl; 
    } 
} 