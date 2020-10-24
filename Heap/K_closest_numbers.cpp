#include <iostream>
#include <queue> 
using namespace std; 
typedef pair<int, int> ppi;


void k_largest(int arr[], int n, int k, int X){
	priority_queue<ppi > max_heap;
	vector<int> sub;
	for (int i = 0; i < n; ++i)
		{
			max_heap.push(make_pair(abs(arr[i]-X), arr[i]));
			if(max_heap.size()>k){
				max_heap.pop();
			}
		}

	cout<<"Differnce\t"<< "Number in array"<<endl;
	while(!max_heap.empty()){

		cout<<max_heap.top().first<<"\t"<<"\t"<<max_heap.top().second<<endl;
		max_heap.pop();
	}
	
	return;
}


int main(){

	int arr[]={5,6,7,8,9};
	int n=sizeof(arr)/sizeof(arr[0]);
	int k=3;
	int X=7;
	k_largest(arr,n,k,X);

	return 0;
}