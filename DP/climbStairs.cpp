#include<iostream>
using namespace std;



int countWays(int s, int m){
	int dp[s];
	dp[0]=1;
	dp[1]=1;
	for(int i = 2; i < s+1; i++)  
    { 
       dp[i] = 0; 
         
       for(int j = 1; j <= m && j <= i; j++){
       	dp[i] += dp[i - j]; 
       } 
          
    } 
	return dp[s-1];
}




int main(){
	int s=5, m=3;
	s=s+1;
	cout<<countWays(s,m);
	return 0;
}