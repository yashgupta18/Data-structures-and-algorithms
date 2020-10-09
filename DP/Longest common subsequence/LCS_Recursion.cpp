#include<iostream>
using namespace std;


int LCS(string X, string Y, int n, int m){

	if(n==0 || m==0) return 0;

	if(X[n-1]==Y[m-1]){
		return 1+ LCS(X,Y, n-1, m-1);
	}
	else{
		return max( LCS(X,Y, n-1, m),LCS(X,Y, n, m-1));
	}
}



int main(){
	string X="abceh";
	int n=X.length();
	string Y="abdefhr";
	int m=Y.length();
	cout<<"Longest subsequence = "<<LCS(X,Y, n,m)<<endl;


}