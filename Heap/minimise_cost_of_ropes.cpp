#include <iostream>
#include <queue> 
using namespace std; 

void ropes_minimize(int arr[], int n){
	priority_queue<int, vector<int>,greater<int> > min_heap;
	// cout<<"1";
	for (int i = 0; i <n; ++i)
	{
		min_heap.push(arr[i]);
	}

	int x1=0,x2=0,x3=0, totalcost=0;
	while(min_heap.size()>=2){
		x1=min_heap.top();
		min_heap.pop();

		x2=min_heap.top();
		min_heap.pop();

		x3=x1+x2;
		totalcost=totalcost+x3;
		min_heap.push(x3);
	}
	cout<<"Total minimized Cost= "<<totalcost;

	return;
}


int main(){

	int arr[]={1,2,3,4,5};
	int n=sizeof(arr)/sizeof(arr[0]);
	ropes_minimize(arr,n);

	return 0;
}