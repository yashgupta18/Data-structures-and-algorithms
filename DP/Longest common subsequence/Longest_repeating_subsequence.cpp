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
		for (int j = 0; j < n+1; ++j){
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
		for (int j = 1; j < n+1; ++j)
		{
			//if(they are at same position don't include them)
			if(X[i-1]==Y[j-1] && i!=j){ 
				//if char at pos X[i-1]==Y[j-1], increase the count 
				t[i][j] = 1+ t[i-1][j-1];
			}
	
			else{
				//if it is not same see for both by decreasing size of each and choosing the max 
				t[i][j] = max(t[i-1][j],t[i][j-1]);
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

	cout<<"Longest Repeating Subsequence = "<< t[m][n];	
	return;
}

int main(){
	string X="AABEBCDD";
	//AABBDD- longest repeating subsequence == 3(ABD)
	int m=X.length();
	LCS(X,X,m,m);
	return 0;
}