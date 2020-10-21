#include <iostream>
// #include<unordered_map>
// #include<vector>
#include <queue> 
// #include<stack>
using namespace std; 
  

void k_placesAway(int arr[], int n,int k){

	priority_queue<int,vector<int>,greater<int> > min_heap;
	vector<int> res;
	for (int i = 0; i <n; ++i)
	{
		min_heap.push(arr[i]);

		if (min_heap.size()==k+1)
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
		cout<<res[i]<<endl;
	}
}


void k_largest(int arr[], int n, int k){
	// priority_queue<int> max_heap;
	priority_queue<int,vector<int>,greater<int> > min_heap;
	vector<int> res;
	for (int i = 0; i <n; ++i)
	{
		//use max heap or min heap
		// max_heap.push(arr[i]);
		if (min_heap.size()==k)
		{
			if (min_heap.top()<arr[i])
			{
				min_heap.pop();	
				min_heap.push(arr[i]);
			}
		}
		else{
			min_heap.push(arr[i]);
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


	// int arr[]={6,5,3,2,8,10,9};
	// int n=sizeof(arr)/sizeof(arr[0]);
	// int k=3;
	// k_placesAway(arr,n,k);

	int arr[]={1, 23 ,12, 9, 30 ,2, 50};
	int n=sizeof(arr)/sizeof(arr[0]);
	int k=3;
	k_largest(arr,n,k);

	return 0;
}