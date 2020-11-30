#include <iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<string>
using namespace std; 

// Given an array of integers, find if it’s possible to remove exactly one integer from the array that divides the array into two subarrays with the same sum.



// https://www.geeksforgeeks.org/find-if-array-can-be-divided-into-two-subarrays-of-equal-sum/

void divideArray(int arr[], int n){
    int sum=0;
    for (int i = 0; i < n; ++i)
    {
        sum+=arr[i];
    }

    int sumSoFar=0;
    for (int i = 0; i < n; ++i)
    {
        if(2*sumSoFar + arr[i]==sum){
            cout<<"Division is possible";
            return;
        }
        sumSoFar+=arr[i];
    }
    cout<<"Division not possible";
    return;
   
}

// Driver Code
int main()
{
    int arr[] = {6, 2, 3, 2, 1}; 
   int n=sizeof(arr)/sizeof(arr[0]);
   divideArray(arr, n);
    return 0;
}



