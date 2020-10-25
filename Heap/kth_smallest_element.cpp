#include <iostream>
#include <queue> 
using namespace std; 

void k_smallest(int arr[], int n, int k){
	// priority_queue<int> max_heap;
	priority_queue<int> max_heap;

	for (int i = 0; i <n; ++i)
	{
		max_heap.push(arr[i]);
		if (max_heap.size()>k)
		{
				max_heap.pop();	
		}
		
	}
	cout<<max_heap.top();
	return;
}


int main(){

	int arr[]={7,10,4,3,20,15};
	int n=sizeof(arr)/sizeof(arr[0]);
	int k=3;
	k_smallest(arr,n,k);

	return 0;
}