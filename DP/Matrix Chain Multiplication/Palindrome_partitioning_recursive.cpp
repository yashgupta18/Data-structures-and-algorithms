#include<iostream>

using namespace std;

int min(int a, int b){
	 return (a < b) ? a : b; 
}
int isPalindrome(string S, int i, int j){
	while(i<=j){
		if(S[i]==S[j]){
			i++;
			j--;
		}
		else{
			return 0;
		}
	}
	return 1;
}

int solve(string S, int i, int j){
	if(i>=j) return 0;

	if(isPalindrome(S,i,j)==1){
		return 0;
	}

	int ans=INT_MAX;
	for (int k= i; k <= j-1; ++k)
	{
		int temp = solve(S, i, k) + solve(S, k+1, j) + 1;
		ans=min(temp, ans);
	}

	return ans;
}

int main(){
	string S="NITIK";
	int n=S.length();
	cout<<solve(S,0,n-1);
}