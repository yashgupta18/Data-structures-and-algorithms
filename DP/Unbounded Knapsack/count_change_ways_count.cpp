#include<iostream>
using namespace std;

int max(int a, int b) 
{ 
    return (a > b) ? a : b; 
} 


int coin_change_count(int arr[], int sum, int n) 
{ 
    int i, j; 
    int t[n + 1][sum + 1]; 
    
    for (int i = 0; i <= n; i++) 
        t[i][0] = true; 

    // If sum is not 0 and set is empty, 
    // then answer is false 
    for (int i = 1; i <= sum; i++) 
        t[0][i] = false; 
    //for understanding
    for (i = 1; i <= n; i++) { 
        for (j = 1; j <= sum; j++) { 
            t[i][j]=0;
        } 
    }

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
            //if current coins value is less than sum j
            if(arr[i-1]<=j){
                //check how many coins if current coin is selected + check if it can be filled without current i
                t[i][j]=( t[i][j-arr[i-1]] + t[i-1][j] );
            }
            else{
                //just use the above value from table if coin value is greater than sum j
                t[i][j]= t[i-1][j];

            }

        } 
    }
    cout<<endl;

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
    cout<<"Coint Max Count ways="<<" ";
    return t[n][sum]; 
}

int main(){
	int arr[] ={ 1,2,3 };
    int sum = 5; 
    int n = sizeof(arr) / sizeof(arr[0]); 
	cout<<coin_change_count(arr,sum,n);


}