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
			}else{
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
				//if they match increase 1
				t[i][j]= 1 + t[i-1][j-1];
			}
			else{
				//if strings dont match start from 0
				t[i][j]=0;
			}
		}
	}

	int max_val=INT_MIN;
	for (int i = 0; i < m+1; ++i)
	{
		for (int j = 0; j < n+1; ++j)
		{
			//store the max substring count from the table
			max_val=max(max_val, t[i][j]);
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

	cout<<"MAX Substring length= "<<max_val;
	return;

}




int main(){
	string X="abcde";
	int m=X.length();
	string Y="ababcde";
	int n=Y.length();
	LCS(X,Y,m,n);
}