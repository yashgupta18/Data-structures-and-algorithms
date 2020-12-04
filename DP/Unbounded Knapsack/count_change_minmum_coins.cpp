#include<iostream>
using namespace std;

int min(int a, int b) 
{ 
    return (a < b) ? a : b; 
} 


int coin_change_count(int arr[], int sum, int n) 
{ 
    int i, j; 
    int t[n + 1][sum + 1]; 
    memset(t, 0, sizeof(t));
    for (int i = 1; i < n+1; i++) 
        t[i][0] = 0; 

    //first row set  int_max
    for (int i = 0; i < sum+1; i++) 
        t[0][i] = INT_MAX-1; 

    //for setting 2nd row(only this ques exception) check notes
     // ****IMPORTANT STEP****
    // for (int j = 1; j < sum+1; ++j)
    // {
    //     if((j%arr[0])==0){
    //         t[1][j]=j%arr[0];
    //     }
    //     else{
    //         t[1][j]=-1;
    //     }
    // }
    //for understanding
    // for (i = 1; i <= n; i++) { 
    //     for (j = 1; j <= sum; j++) { 
    //         t[i][j]=0;
    //     } 
    // }

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

                // ****IMPORTANT STEP****

                //add one if the current coin at ith pos is selected or just copy value from above
                t[i][j]=min( t[i][j-arr[i-1]] + 1 , t[i-1][j] );
            }
            else{
                //just use the above value from table as curr val of arr[i] is greater than the sum j
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
    cout<<"Minimum number of coins="<<" ";
    return t[n][sum]; 
}

int main(){
	int arr[] ={ 1,5,7,9,11 };
    int sum = 22; 
    int n = sizeof(arr) / sizeof(arr[0]); 
	cout<<coin_change_count(arr,sum,n);


}