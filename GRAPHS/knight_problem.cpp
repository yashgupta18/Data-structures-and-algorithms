#include <iostream>
#include <vector>
using namespace std;
#define N 8 
  
// int solveKTUtil(int x, int y, int movei, int sol[N][N], int xMove[], int yMove[]); 
  
/* A utility function to check if i,j are  
valid indexes for N*N chessboard */
bool valid(int nx, int ny) 
{
  if(nx<0 || nx>N || ny<0 || ny>N)
    return false;
  return true;
  // return(nx>=0 && nx<N && ny>=0 && ny<N && mat[nx][ny]==-1);
} 

bool go(int mat[N][N],int x, int y, int movei, int dx[N], int dy[N]) 
{ 

   if(movei==N*N){
      return 1;
   }
   // else{
   for (int i = 0; i < 8; ++i)
    {
      int nx=x+dx[i];
      int ny=y+dy[i];
      if (valid(nx,ny) && mat[nx][ny]==-1)
      {
        mat[nx][ny]=movei;
        if(go(mat,nx,ny,movei+1,dx,dy)==1)
        {
          return 1;
        }
        mat[nx][ny]=-1; 
      }
    }
    return 0;
   // }
} 
  
// Driver Code 
int main() 
{ 
  int mat[N][N];
  memset(mat,-1, sizeof(mat));
  mat[0][0]=0;
  int dx[8]={-2,-2,2,2,-1,-1,1,1};
  int dy[8]={-1,1,-1,1,-2,2,-2,2};
  if(go(mat,0,0,1,dx,dy))
  {
    for (int i = 0; i < N; ++i)
      {
        for (int j = 0; j < N; ++j)
        {
          cout<<mat[i][j]<<"\t";
          
        }
        cout<<endl;
        
      }

      cout<<"Built Complete";
    }
    return 0; 
} 
