#include <iostream>
#include <queue> 
#include <unordered_map> 
using namespace std; 
typedef pair<int, pair<int, int> > ppi;

void frequency_sort(int arr[], int n){
	unordered_map<int, int> mp;

	priority_queue<pair<int, int> > max_heap;
	for (int i = 0; i < n; ++i)
		{
			//store pair of arr[i] and freq in mp
			mp[arr[i]]++;
		}

	for(auto i :mp){
		//store freq and arr[i] in heap. sorted acc to freq. max will be at the bottom. bottom k will be final ans
		 max_heap.push(make_pair(i.second, i.first));
	}

	cout<<"Number"<<'\t'<<"FREQ"<<endl;
	while(!max_heap.empty()){
		// cout<<max_heap.top().second<<"\t"<<<<endl;
		int freq=max_heap.top().first;
		int element=max_heap.top().second;
		
		for (int i = 0; i <freq ; ++i)
		{
			//print element times it occors
			cout<<element<<" ";
		}
		max_heap.pop();
	}
	return;
}


int main(){

	int arr[]={1,1,1,1,3, 3,2,2,2,4};
	int n=sizeof(arr)/sizeof(arr[0]);
	frequency_sort(arr,n);

	return 0;
}