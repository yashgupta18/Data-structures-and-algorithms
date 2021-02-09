#include <iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<string>
using namespace std; 


// Maximum consecutive numbers present in an array
// https://www.geeksforgeeks.org/maximum-consecutive-numbers-present-array/
  
int findLongestConseqSubseq(int arr[], int n) 
{ 
    /* We insert all the array elements into 
       unordered set. */
    set<int> S; 
    for (int i = 0; i < n; i++) 
        S.insert(arr[i]); 
  
    // check each possible sequence from the start 
    // then update optimal length 
    int ans = 0; 
    for (int i = 0; i < n; i++) { 
  
        // if current element is the starting 
        // element of a sequence 
        if (S.find(arr[i] - 1) == S.end()) { 
  
            // Then check for next elements in the 
            // sequence 
            int j = arr[i]; 
  
            // increment the value of array element 
            // and repeat search in the set 
            while (S.find(j) != S.end()) 
                j++;  
  
            // Update  optimal length if this length 
            // is more. To get the length as it is  
            // incremented one by one 
            ans = max(ans, j - arr[i]);  
        } 
    } 
    return ans; 
} 
  
// Driver code 
int main() 
{ 
    int arr[] = { 1, 94, 93, 1000, 5, 92, 78 }; 
    int n = sizeof(arr) / sizeof(int); 
    cout << findLongestConseqSubseq(arr, n) << endl; 
    return 0; 
} 


