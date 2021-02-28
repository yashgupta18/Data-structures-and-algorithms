#include<iostream>
#include<vector>
#include<queue>

using namespace std;
// Q. https://codeforces.com/contest/1491/problem/A


int backtrack(int n, int &s[i], int &minCnt){
	for (int i = 0; i < n; ++i)
	{
		int next=s[i]+i;
		if(i==s[])
		s[i]=s[i]-1;
	}
}

int solve(int n){
	int s[n];
		for (int i = 0; i < n; ++i)
		{
			/* code */
			cin>>s[i];
		}

		int minCnt=INT_MAX;
		backtrack(s, minCnt);

}


int main(){
	int tc;
	cin>>tc;
	while(tc--){
		int n;
		cin>>n;
		solve(n);


	}
}