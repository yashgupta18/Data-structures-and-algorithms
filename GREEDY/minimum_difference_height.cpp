#include<iostream>
#include<vector>
using namespace std;

void heights(int arr[], int n, int k){
	sort(arr, arr+n);
	int ans=arr[n-1]-arr[0];
	int small=arr[0]+k;
	int big=arr[n-1]-k;

	for (int i = 1; i < n; ++i)
	{
		int add=arr[i]+k;
		int subract=arr[i]-k;

		if(small<=subract || add<=big)
			continue;

		if(big-subract <= add-small){
			small=subract;
		}else{
			big=add;
		}
	}
	cout<<"Result="<<min(ans, big - small)<<endl;
	return; 
}

int main() 
{ 
    int arr[] = {1, 10, 14, 14, 14, 15};
    int k=3;
    int n = sizeof(arr) / sizeof(arr[0]); 
    heights(arr, n, k); 
    return 0; 
} 