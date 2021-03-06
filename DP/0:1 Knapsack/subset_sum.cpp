#include<iostream>
using namespace std;

int max(int a, int b) 
{ 
    return (a > b) ? a : b; 
} 


int subset_sum(int arr[], int sum, int n) 
{ 
    int i, j; 
    bool t[n + 1][sum + 1]; 
    
    for (int i = 0; i <= n; i++) 
        t[i][0] = true; 

    // If sum is not 0 and set is empty, 
    // then answer is false 
    for (int i = 1; i <= sum; i++) 
        t[0][i] = false; 
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
                //first check if block can be filled without current no. OR it with if it can be filled with current no and remaining sum be filled from above
                t[i][j]=t[i-1][j-arr[i-1]] || t[i-1][j];
            }
            else{
                //just use the above value from table
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
	int arr[] ={ 1,4,10,3,1 };
    int sum = 4; 
    int n = sizeof(arr) / sizeof(arr[0]); 
	cout<<subset_sum(arr,sum,n);
}