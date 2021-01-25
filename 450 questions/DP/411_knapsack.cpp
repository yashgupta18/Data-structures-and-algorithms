#include <iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<stack>
#include<map>
using namespace std; 
// #def

// bool isInside(int x, int y, int N) 
// { 
//     if (x >= 1 && x <= N && y >= 1 && y <= N) 
//         return true; 
//     return false; 
// } 
  

int knapsack(int W, int wt[], int val[], int n){
	int i, j; 
    int t[n + 1][W + 1]; 
  
    // Build table t[][] in bottom up manner 
    for (i = 0; i <= n; i++) { 
        for (j = 0; j <= W; j++) { 
        	// initialize 1st row and column with 0 rest with -1
            if (i == 0 || j == 0){
            	t[i][j] = 0; 
            }else{
            	t[i][j] = -1; 
            } 
        } 
    }

    for (int i = 1; i <= n; ++i)
     {
     	/* code */
     	for (int j = 1; j <=W; ++j)
     	{
     		/* code */
     		if(wt[i-1]<=j){
     			t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]], t[i-1][j]);
     		}
     		else{
     			t[i][j]=t[i-1][j];
     		}
     	}
     }

     return t[n][W]; 
	
}


int main(){
	int val[] = { 1,4,5,7 }; 
    int wt[] = { 1,3,4,5 }; 
    int W = 7; 
    int n = sizeof(val) / sizeof(val[0]); 
	
	//set all values as -1 in t
	// memset(t,-1,sizeof(t));
	cout<<knapsack(W,wt,val,n);
	return 0;
}







