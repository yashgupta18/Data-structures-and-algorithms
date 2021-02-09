#include <iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<string>
using namespace std; 


// Q.Find the smallest positive integer value that cannot be represented as sum of any subset of a given array
// Explaination https://medium.com/dexters-lab/eli5-find-the-smallest-positive-integer-value-that-cannot-be-represented-as-sum-of-any-subset-of-f8ea2488184b

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



