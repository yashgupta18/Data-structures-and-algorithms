#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream> 
using namespace std; 
#define max 4 
  
// Recursive function to find the required number of ways 
int countWays(int index, int cnt, int dp[][max], int n, int m, int k) 
{ 
    // if(dp[index][cnt]!=-1) return dp[index][cnt];
  
    // When all positions are filled 
    if (index == n) { 
  
        // If adjacent pairs are exactly K 
        if (cnt == k) 
            return 1; 
        else
            return 0; 
    } 
  
    // If already calculated 
    if (dp[index][cnt] != -1) 
        return dp[index][cnt]; 
  
    int ans = 0; 
    
    // Next position filled with same color 
    ans += countWays(index + 1, cnt, dp, n, m, k); 
  
    // Next position filled with different color 
    // So there can be m-1 different colors 
    ans += (m - 1) * countWays(index + 1, cnt + 1, dp, n, m, k); 
    
    // for (int i = 0; i < index+1; ++i)
    // {
    //     for (int j = 0; j < cnt+1; ++j)
    //     {
    //         if(){
    //             dp[index][cnt]=ans+ max(dp[i+1][j+1], dp[i+1][j]);
    //         }

    //         else{
    //              dp[index][cnt]=dp[i+1][j];
    //         }
            
    //     }
    // }

    cout<<"After dp"<<endl;
    for (int i = 0; i < index+1; ++i)
    {
        for (int i = 0; i < cnt+1; ++i)
        {
            cout<<dp[index][cnt]<<" ";
        }
        cout<<endl;
    }
    return dp[index][cnt] = ans; 
} 
  
// Driver Code 
int main() 
{ 
    int n = 3, m = 2, k = 1; 
    int dp[n + 1][max]; 
    memset(dp, -1, sizeof dp); 
  
    cout << m * countWays(1, 0, dp, n, m, k); 
}  