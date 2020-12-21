#include <iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<string>
using namespace std; 


//make 2 arr to store max of left and right of current index

int minSum(int arr[], int n){
    int maxPossible=0;

    if(arr[0]!=1 || n==0){
      return maxPossible+1;
    }

    maxPossible=1;

    for (int i = 1; i < n; ++i)
    {
      if(arr[i]> maxPossible+1){
        break;
      }

      maxPossible+=arr[i];
    }

    return maxPossible+1;
}

// Driver Code
int main()
{
   int arr[] = {1, 1, 3, 4};
   int n=sizeof(arr)/sizeof(arr[0]);
   cout<<minSum(arr, n);
    return 0;
}



