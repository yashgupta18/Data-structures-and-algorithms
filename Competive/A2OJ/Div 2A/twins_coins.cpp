#include <iostream>
// #include <bits/stdc++.h> 
#include<unordered_map>
#include<vector>
#include<queue>
#include<stack>
#include <numeric>      // std::accumulate
#include<map>
#include<string>
#include<cstring>
#include<regex>

using namespace std;

int coinsDivide(vector<int> coins, int n){
	if(n<=1) return 1;
	int sum=accumulate(coins.begin(), coins.end(), 0);
	sort(coins.begin(), coins.end(), greater<int>()); 
	int elderSum=0;
	int ptr=0, numsOfCoins=0;
	while(1){
		if(elderSum>sum) {
			return numsOfCoins;
		}

		elderSum=elderSum + coins[ptr];
		sum=sum-coins[ptr];
		numsOfCoins++;
		ptr++;
	}
}

int main(){
	int n,a;
	cin>>n;
	vector<int> coins;
	for (int i = 0; i < n; ++i)
	{
		cin>>a;
		coins.push_back(a);
	}
	int ans = coinsDivide(coins, n);
	cout<<ans;

	return 0;
}