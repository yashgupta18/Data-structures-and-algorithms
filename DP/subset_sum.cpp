#include<iostream>
using namespace std;

int max(int a, int b) 
{ 
    return (a > b) ? a : b; 
} 


int knapsack(int arr[], int sum, int n) 
{ 
    int i, j; 
    bool t[n + 1][sum + 1]; 
  
    // Build table t[][] in bottom up manner 
    for (i = 0; i <= n; i++) { 
        for (j = 0; j <= sum; j++) { 
        	// initialize 1st row and column with 0 rest with -1
            if (i == 0){
            	t[i][j] = false; 
            }
            else if(j==0){
            	t[i][j] = true; 
            } 
        } 
    } 

    //for understanding
    cout<<"Before DP"<<endl;
    for (i = 0; i <= n; i++) { 
        for (j = 0; j <= sum; j++) { 
            cout<<t[i][j]<<" ";
        } 
        cout<<endl;
    } 
    cout<<endl;

    
    for (int i = 1; i <= n; i++) { 
        for (int j = 1; j <= sum; j++) { 

            if(arr[i-1]<=j){
                t[i][j]=t[i-1][j-arr[i-1]] || t[i-1][j];
            }
            else{
                t[i][j]= t[i-1][j];
            }

        } 
    }

    // for understanding
    cout<<"After DP"<<endl;
    for (i = 0; i <= n; i++) { 
        for (j = 0; j <= sum; j++) { 
            cout<<t[i][j]<<" ";
        } 
        cout<<endl;
    } 
    cout<<endl; 
    cout<<"Final Ans"<<endl;

    return t[n][sum]; 
}

int main(){
	int arr[] = {2,3,7,8,10}; 
    int sum = 7; 
    int n = sizeof(arr) / sizeof(arr[0]); 
	cout<<knapsack(arr,sum,n);


}