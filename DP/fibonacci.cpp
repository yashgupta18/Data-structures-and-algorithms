#include<iostream>
#include<vector>
using namespace std;


int fibo(int n){
	vector<int> res;
	res.push_back(0);
	res.push_back(1);
	for (int i = 2; i <= n; ++i)
	{
		int ans=res[i-1]+res[i-2];
		res.push_back(ans);

	}
	// cout<<res[n];

	for (int i = 0; i < res.size(); ++i)
	{
		cout<<res[i]<<" ";
	}
}





int main(){
	int n=9;
    fibo(n); 
	return 0;
}