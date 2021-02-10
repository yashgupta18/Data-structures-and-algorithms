#include<iostream>
using namespace std;



int LIS(int arr[], int n){
	int dp[n];
	int globalMax=0;
	for (int i = 0; i < n; ++i)
	{	
		int maxi=0;
		for (int j = 0; j < i; ++j)
		{	
			if(arr[j]<arr[i]){
				if(dp[j]>maxi){
					maxi=dp[j];
				}
			}
		}
		
		dp[i]=maxi+1;
		if(dp[i]>globalMax){
			globalMax=dp[i];
		}
	}
	return globalMax;
}




int main(){
	int arr[]= {50, 3, 10, 7, 40, 80};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<LIS(arr,n);
	return 0;
}