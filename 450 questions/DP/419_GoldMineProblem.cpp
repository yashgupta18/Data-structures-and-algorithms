#include <iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<stack>
#include<map>
using namespace std; 

#define M 4
#define N 4
  
int max(int a, int b) 
{ 
    return (a > b) ? a : b; 
} 

int goldMine(int mat[M][N]){
	int i, j; 
    int t[M+1][N+1]; 


    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if(j==N-1){
                t[i][j]=mat[i][j];
            }
            else{
                t[i][j]=0;
            }
        }
    }

    for (int i = 0; i < M; ++i)
    {
        /* code */
        for (int j = 0; j < N; ++j)
        {
            /* code */
            cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    for (int j = N-2; j >= 0; --j)
    {
        for (int i = M-1; i >=0 ; --i)
        {
            if(i==0){
                t[i][j]=(mat[i][j] + max(t[i][j+1], t[i+1][j+1]));
            }

            if(i==M-1){
                t[i][j]=(mat[i][j] + max(t[i-1][j+1], t[i][j+1]));
            }

            else{
                int p= max(t[i-1][j+1], t[i][j+1]);

                t[i][j]=(mat[i][j] + max(t[i+1][j+1],p));
            }   
        }

    }

    for (int i = 0; i < M; ++i)
    {
        /* code */
        for (int j = 0; j < N; ++j)
        {
            /* code */
            cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    int ans=0;
    for (int i = 0; i < M; ++i)
    {
        /* code */
        //one error otherwise its all fine
        ans=max(t[i][0], ans);
    }

    return ans;
	
}


int main(){
	int mat[M][N] = { {1, 3, 1, 5}, 
                    {2, 2, 4, 1}, 
                    {5, 0, 2, 3}, 
                    {0, 6, 1, 2} 
                    }; 

	cout<<goldMine(mat);
	return 0;
}







