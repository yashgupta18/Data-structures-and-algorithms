#include<iostream>
using namespace std;

int max(int a, int b) 
{ 
    return (a > b) ? a : b; 
} 


void LCS(string X, string Y, int m, int n){
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

	cout<<"Before DP"<<endl;
	for (int i = 0; i < m+1; ++i)
	{
		for (int j = 0; j < n+1; ++j)
		{
			cout<<t[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;

	for (int i = 1; i < m+1; ++i)
	{
		for (int j= 1; j < n+1; ++j)
		{
			if(X[i-1]==Y[j-1]){
				t[i][j]=1+t[i-1][j-1];
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
			cout<<t[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;

	cout<<t[m][n]<<endl;

	//if length of LCS is same as length of string X, then X is subsequence of 
	if(t[m][n]==m){
		cout<<"true";
		return;
	}
	else{
		cout<<"False";
		return;
	}
}

int main(){
	// Q= is string X subsequence of Y or not?
	string X="AXY";
	int m=X.length();
	string Y="ADXCPY";
	int n=Y.length();
	LCS(X,Y,m,n);
	return 0;
}