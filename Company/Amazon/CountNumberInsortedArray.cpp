#include <iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std; 

 
int firstPtr(int arr[], int n, int k){
	int start=0, end=n-1, res=-1;

	while(start<=end){
		int mid=start+ ((end-start)/2);
		if(arr[mid]==k){
			res=mid;
			end=mid-1;
		}
		else if(arr[mid]>k){
			end=mid-1;
		}
		else{
			start=mid+1;
		}
	}
	return res;
}

int secondPtr(int arr[], int n, int k){
	int start=0, end=n-1, res=-1;

	while(start<=end){
		int mid=start+ ((end-start)/2);
		if(arr[mid]==k){
			res=mid;
			start=mid+1;
		}
		else if(arr[mid]>k){
			end=mid-1;
		}
		else{
			start=mid+1;
		}
	}
	return res;
}

int main(){
	int arr[] = {1,1,2,2,3,3,3,3,3,4,5,6};
	int n=sizeof(arr)/sizeof(arr[0]);
	int k=3;
	int first=firstPtr(arr,n,k);
	int second=secondPtr(arr, n,k);
	cout<<first<<" "<<second<<endl;
	int ans=second-first+1;
	cout<<"Occurences="<<ans;

	//Alternate formula
	// int *low = lower_bound(arr, arr+n, x); 
	// int *high = upper_bound(low, arr+n, x);    
	return 0;
}