#include<iostream>
using namespace std;

int max(int a, int b) 
{ 
    return (a > b) ? a : b; 
} 


int knapsack(int W, int wt[], int val[], int n) 
{ 
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

    //for understanding
    for (i = 0; i <= n; i++) { 
        for (j = 0; j <= W; j++) { 
            cout<<t[i][j]<<" ";
        } 
        cout<<endl;
    } 
    cout<<endl;

    //
    for (int i = 1; i <= n; i++) { 
        for (int j = 1; j <= W; j++) { 
            if (wt[i - 1] <= j) 
            	//if we have a valid element we either selct it or reject it 
                t[i][j] = max( 
                    val[i - 1] + t[i - 1][j - wt[i - 1]], 
                    t[i - 1][j]); 
            else
            	//cannot put current object in knapsack. it is not valid
            	//value at current block equal to prev
                t[i][j] = t[i - 1][j]; 
        } 
    }

    //for understanding
    for (i = 0; i <= n; i++) { 
        for (j = 0; j <= W; j++) { 
            cout<<t[i][j]<<" ";
        } 
        cout<<endl;
    } 
    cout<<endl; 
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
	// for (int i = 0; i <=n; ++i)
	// {
	// 	for (int j = 0; j <=n; ++j)
	// 	{
	// 		cout<<t[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }


}