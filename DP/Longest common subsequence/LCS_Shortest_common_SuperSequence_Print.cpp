#include<iostream>
#include<string>

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
			if(X[i-1]==Y[j-1]){ 
				//if last char is same reduce size of both strings
				t[i][j] = 1+t[i-1][j-1];
			}
			else{
				//if last is not same see for both by decreasing size of each and choosing the max 
				t[i][j] = max(t[i-1][j], t[i][j-1]);
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

	int count=0;
	// cout<<"Length of Shortest Common SuperSequence = m+n-LCS of X & Y = ";
	// cout<< m+n-t[m][n]<<endl;

	//print
	int i=m, j=n;
	string ans="";
	while(i>0 && j>0){
		// if last char in both string is equal push it in ans and go to diagnol left up
		if(X[i-1]==Y[j-1]){
			ans.push_back(X[i-1]);
			cout<<i<<" "<<j<<endl;
			i--;
			j--;
		}
		else{
			//check for max value in up and left block and move there.
			if(t[i-1][j] < t[i][j-1]){
				ans.push_back(Y[j-1]);
				cout<<i<<" "<<j<<endl;
				j--;
			}
			else{
				ans.push_back(X[i-1]);
				cout<<i<<" "<<j<<endl;
				i--;
			}
		}
	}

	while(i>0){
		ans.push_back(X[i-1]);
		i--;
	}

	while(j>0){
		ans.push_back(Y[j-1]);
		j--;
	}

	reverse(ans.begin(), ans.end());
	cout<<ans;
	return;
}

int main(){
	string X="AGGTAB";
	int m=X.length();
	string Y="GXTXAYB";
	int n=Y.length();
	LCS(X,Y,m,n);
}