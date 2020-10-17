#include<iostream>
using namespace std;

int solve(string X,string Y){
	//if length is not same not possible
	if(X.length()!=Y.length()){
		return 0;
	}

	//if X and Y is ditto same return 1
	if(X.compare(Y)==0){
		return 1;
	}

	int n=X.length();
	bool flag=false;

	for (int i= 1; i< n; ++i)
	{
		// condition 1
		// if swap happens
		// compare x.first with y.second and x.second with y.first

		//condition 2
		// if no swapping
		// compare x.first with y.first and x.second with y.second

		// if(condn 1 || condn 2)

		//  **--------------------------------------Condition 1-----------------------------------------***     **--------------------------------------Condition 2-----------------------------------------***
		if((solve(X.substr(0,i), Y.substr(n-i, i))==true && solve(X.substr(i,n-i), Y.substr(0,n-i))==true ) || (solve(X.substr(0,i), Y.substr(0, i))==true && solve(X.substr(i,n-i), Y.substr(i,n-i))==true)){
			//if condn is true it is scrambled
			flag=true;
			//get out of loop
			break;
		}
	}
	return flag;
}

int main(){
	string X="great";
	string Y="rgeat";
		int ans=solve(X,Y);
		if(ans){
			cout<<"Scrambled";
		}else{
			cout<<"Not Scrambled";
		}
	return 0;
}