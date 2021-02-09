#include <iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<string>
using namespace std; 


int subarray(int arr[], int n) {
        //check if all are less than 0 then return
        int high=INT_MIN;
        for(int i=0; i<n; i++){
            if(arr[i]>high){
                high=arr[i];
            }
        }
        if(high<0) return high;
        
        int currMax=0;
        int backMax=0;
        int forward[n];
        int backward[n];
        //kadane's from left to right
        for(int i=0; i<n; i++){
            currMax=max(arr[i], currMax+arr[i]);
            forward[i]=currMax;
        }
        currMax=0;
        int totalMax=0;
        //kadane's from right to left
        for(int i=n-1; i>=0; i--){
            currMax=max(arr[i], currMax+arr[i]);
            backward[i]=currMax;
            totalMax=max(totalMax, currMax);
        }
        
        // check if ans is max with deletion or without deletion
        int ans=totalMax;
        for(int i=1; i<n-1; i++){
            ans=max(ans,forward[i-1]+backward[i+1]);
        }
        
        return ans;        
}


int main()
// Q. Given an array of integers, return the maximum sum for a 
// non-empty subarray (contiguous elements) with at most one element 
// deletion. In other words, you want to choose a subarray and optionally
 // delete one element from it so that there is still at least one element left 
// and the sum of the remaining elements is maximum possible.


// https://www.youtube.com/watch?v=AxkYOnS-hjs&ab_channel=KelvinChandra
// https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/
{
    int arr[] = {1,-2,-2,3}; 
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<subarray(arr, n);
    return 0;
}



