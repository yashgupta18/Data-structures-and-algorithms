#include <iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<string>
using namespace std; 


// https://www.geeksforgeeks.org/given-an-array-arr-find-the-maximum-j-i-such-that-arrj-arri/

// Given an array arr[], find the maximum j – i such that arr[j] > arr[i]

int maxIndexDifference(int arr[], int n){
    int LMin[n],RMax[n];
    LMin[0]=arr[0];
    RMax[n-1]=arr[n-1];
    for (int i = 1; i < n; ++i)
    {   
        LMin[i]=min(LMin[i-1], arr[i]);
    }

    for (int i = n-2; i >=0; --i)
    {
        RMax[i]=max(arr[i], RMax[i+1]);
    }

    int a=0, b=0, maxIndex=0;
    while(a<n && b<n){
        if(LMin[a]<RMax[b]){
            maxIndex=max(maxIndex, b-a);
            b++;
        }
        else{
            a++;
        }

    }
    cout<<maxIndex;
   
}

// Driver Code
int main()
{
   int arr[] = { 9, 2, 3, 4, 5,6, 7, 8, 18, 0 };
   int n=sizeof(arr)/sizeof(arr[0]);
   maxIndexDifference(arr, n);
   // cout<<ans;
    return 0;
}



