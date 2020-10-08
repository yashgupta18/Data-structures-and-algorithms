#include<iostream>
using namespace std;

int max(int a, int b) 
{ 
    return (a > b) ? a : b; 
} 

void subset_sum_count(int arr[], int sum, int n) 
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
            if(arr[i-1]<=j){
                //first check if block can be filled without current no. OR it with if it can be filled with current no and remaining sum be filled from above
                t[i][j]=( t[i-1][j-arr[i-1]] + t[i-1][j] );
            }
            else{
                //just use the above value from table
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
    cout<<"Count="<<" "<<t[n][sum];
    return; 
}

void count_subset_difference(int arr[], int diff,int n) 
{ 
    int sum=0;
    for (int i = 0; i < n; ++i)
    {
        sum=sum+arr[i];
    }
    //s1 is sum of first subset, s2 of second subset. 
    // (Derived formula)
    //DERIVATION
    // s1+s2=sum
    // s1-s2=diff
    // s1=(sum+diff)/2
    int s1=(sum/2) + (diff/2);
    
    //use subset sum count function.
    subset_sum_count(arr, s1, n);
    return;
}



int main(){
	int arr[] ={ 1,1,2,3 };
    int diff=1;
    int n = sizeof(arr) / sizeof(arr[0]); 
	count_subset_difference(arr,diff,n);


}