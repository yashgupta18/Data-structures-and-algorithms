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
			min_heap.pop();		
		}

	}
	
	for (int i = 0; i < k; ++i)
		{
			// cout<<max_heap.top()<<endl;
			// max_heap.pop();
			cout<<min_heap.top()<<endl;
			min_heap.pop();
		}	
}


int main(){

	int arr[]={1, 23 ,12, 9, 30 ,2, 50};
	int n=sizeof(arr)/sizeof(arr[0]);
	int k=3;
	k_largest(arr,n,k);

	return 0;
}