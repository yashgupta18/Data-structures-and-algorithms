#include<iostream>

using namespace std;
int t[100][100];

int min(int a, int b){
	 return (a < b) ? a : b; 
}
int isPalindrome(string S, int i, int j){
	while(i<j){
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
	if(t[i][j]!=-1){
		return t[i][j];
	}

	if(isPalindrome(S,i,j)==1){
		return 0;
	}

	int ans=INT_MAX;
	for (int k= i; k <= j-1; ++k)
	{
		int temp = solve(S, i, k) + solve(S, k+1, j) + 1;
		ans=min(temp, ans);
	}
	t[i][j]=ans;
	return t[i][j];
}

int main(){
	string S="NITIK";
	int n=S.length();
	memset(t,-1, sizeof(t));

	cout<<"Before DP"<<endl;
	for (int p = 0; p < n; ++p)
	{
		for (int q = 0; q < n; ++q)
		{
			cout<<t[p][q]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;


	cout<<"ANS= "<<solve(S,0,n-1)<<endl;


	cout<<"After DP"<<endl;
	for (int p = 0; p < n; ++p)
	{
		for (int q = 0; q < n; ++q)
		{
			cout<<t[p][q]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;

}