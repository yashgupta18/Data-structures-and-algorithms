#include <iostream>
#include <queue> 
using namespace std; 
  
void k_largest(int arr[], int n, int k){
	priority_queue<int,vector<int>,greater<int> > min_heap;
	vector<int> res;
	for (int i = 0; i <n; ++i)
	{
		//use max heap or min heap
		min_heap.push(arr[i]);
		if (min_heap.size()>k)
		{
			res.push_back(min_heap.top());
			min_heap.pop();	
		}

	}
	
	while(!min_heap.empty()){
		res.push_back(min_heap.top());
			min_heap.pop();	
	}

	for (int i = 0; i < n; ++i)
	{
		cout<<res[i]<<" ";  
	}
	return;
}


int main(){

	int arr[]={6,5,3,2,8,10,7};
	int n=sizeof(arr)/sizeof(arr[0]);
	int k=3;
	k_largest(arr,n,k);

	return 0;
}