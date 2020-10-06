#include<iostream>
using namespace std;

int max(int a, int b) 
{ 
    return (a > b) ? a : b; 
} 


int knapsack(int W, int wt[], int val[], int n) 
{ 
    int i, j; 
    int K[n + 1][W + 1]; 
  
    // Build table K[][] in bottom up manner 
    for (i = 0; i <= n; i++) { 
        for (j = 0; j <= W; j++) { 
            if (i == 0 || j == 0) 
                K[i][j] = 0; 
        } 
    } 

    for (int i = 1; i <= n; i++) { 
        for (int j = 1; j <= W; j++) { 
            if (wt[i - 1] <= j) 
                K[i][j] = max( 
                    val[i - 1] + K[i - 1][j - wt[i - 1]], 
                    K[i - 1][j]); 
            else
                K[i][j] = K[i - 1][j]; 
        } 
    } 
    return K[n][W]; 
}

int main(){
	int val[] = { 60, 100, 120 }; 
    int wt[] = { 10, 20, 30 }; 
    int W = 50; 
    int n = sizeof(val) / sizeof(val[0]); 
	
	//set all values as -1 in t
	// memset(t,-1,sizeof(t));
	cout<<knapsack(W,wt,val,n);
	// for (int i = 0; i <=n; ++i)
	// {
	// 	for (int j = 0; j <=n; ++j)
	// 	{
	// 		cout<<t[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }


}