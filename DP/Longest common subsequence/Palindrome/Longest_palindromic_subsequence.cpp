#include<iostream>
using namespace std;

int max(int a, int b) 
{ 
    return (a > b) ? a : b; 
} 



int LCS(string X, string Y, int m, int n){
	int t[m+1][n+1];
	for (int i = 0; i < m+1; ++i)
	{
		for (int j = 0; j < n+1; ++j)
		{
			if(i==0 || j==0){
				t[i][j]=0;
			}
			else{
				t[i][j]=-1;
			}
		}
	}

	cout<<endl<<"Before DP"<<endl;
	for (int i = 0; i < m+1; ++i)
	{
		for (int j = 0; j < n+1; ++j)
		{
			cout<<t[i][j]<<"\t"<<" ";
		}
		cout<<endl;
	}
	cout<<endl;

	for (int i = 1; i < m+1; ++i)
	{
		for (int j = 1; j < n+1; ++j)
		{
			if(X[i-1]==Y[j-1]){
				t[i][j]=1+ t[i-1][j-1];
			}
			else{
				t[i][j]= max(t[i-1][j], t[i][j-1]);
			}
		}
	}

	cout<<"After DP"<<endl;
	for (int i = 0; i < m+1; ++i)
	{
		for (int j = 0; j < n+1; ++j)
		{
			cout<<t[i][j]<<"\t"<<" ";
		}
		cout<<endl;
	}
	cout<<endl;

	return t[m][n];
}

void LPS(string X, int m){
	//store reverse of X in Y
	string Y=string(X.rbegin(), X.rend());
	int n=Y.length();
	//call LCS on X & Y
	int ans=LCS(X, Y, m, n);
	cout<<"Longest Palindromic subsequence = "<<ans<<endl;
	return;
}

int main(){
	  
	string X="AGBCBA";
	int m=X.length();
	LPS(X,m);
	return 0;
}