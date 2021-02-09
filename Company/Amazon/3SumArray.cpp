#include <iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<string>
using namespace std; 


//make 2 arr to store max of left and right of current index

void sumFind(int arr[], int n, int sum){
    for (int i = 0; i < n; ++i)
    {
        int l=i+1, r=n-1;
        // int curr=sum-arr[i];
        while(l<r){
            if(arr[i]+arr[l]+arr[r]==sum){
                cout<<"PAIR="<<arr[i]<<" "<<arr[l]<<" "<<arr[r]<<endl;
                l++;
                r--;
            }
            
            else if(arr[i]+arr[l]+arr[r]<sum){
                l++;
            }

            else{
                r--;
            }
        }
    }
    return;
}

// Driver Code
int main()
{
   int arr[] = {12, 3, 6, 1, 6, 9};
   int n=sizeof(arr)/sizeof(arr[0]);
   int sum=24;
   sumFind(arr, n, sum);
    return 0;
}



