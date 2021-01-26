#include <iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<stack>
#include<map>
using namespace std; 
// #def

// bool isInside(int x, int y, int N) 
// { 
//     if (x >= 1 && x <= N && y >= 1 && y <= N) 
//         return true; 
//     return false; 
// } 
  

int friendsPair(int n){
	// if(n==1) return 1;
 //    if(n==2) return 2;

 //    return friendsPair(n-1) + (n-1) * friendsPair(n-2);

    int dp[n+1];
    dp[1]=1;
    dp[2]=2;
    for (int i = 3; i <= n; ++i)
    {
        /* code */
        dp[i]=dp[i-1] + (i-1)*(dp[i-2]);

    }
	
    return dp[n];
}


int main(){
	
    int n = 3; 
	cout<<friendsPair(n);
	return 0;
}







