#include <iostream>
#include <cmath>
#include <queue>
#include <utility>
#include <iomanip>      // std::setprecision
#include <algorithm>

#define ll long long int
#define mod 1000000007
using namespace std;


int* solve(int k){
	int* dp= new int[100005];
	dp[0]=1;
	for (int i = 1; i <= 100001; ++i)
	{
		/* code */
		if(i<k){
			dp[i]=dp[i-1];
		}else{
			dp[i]=((dp[i-1]%mod) + (dp[i-k]%mod)%mod);
		}
	}
	for (int i = 1; i <= 100001; ++i){
		dp[i]=((dp[i-1]%mod) + (dp[i]%mod)%mod);
	}
	return dp;
}

int main() {
	int t,k;
	cin>>t>>k;
	int* dp=solve(k);
	while(t--){
		int a,b;
		cin>>a>>b;
		cout<<(dp[b]-dp[a-1] +mod)%mod<<endl;
	}	

	return 0;
}


