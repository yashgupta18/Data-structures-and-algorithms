#include <iostream>
#include <queue> 
using namespace std; 

int k_smallest(int arr[], int n, int k){
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
	return max_heap.top();;
}

int sumKth(int X1, int X2, int arr[],int n){
	int sum=0;
	for (int i = 0; i <n ; ++i)
	{
		if(arr[i]>X1 && arr[i]<X2){
			sum=sum+arr[i];
		}
	}

	return sum;
}

int main(){

	int arr[]={1,3,12,5,15,11};
	int n=sizeof(arr)/sizeof(arr[0]);
	int k1=3;
	int k2=6;
	int X1=k_smallest(arr,n,k1);
	int X2=k_smallest(arr,n,k2);
	cout<<sumKth(X1,X2,arr,n);

	return 0;
}