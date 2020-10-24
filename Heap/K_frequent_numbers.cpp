#include <iostream>
#include <queue> 
#include <unordered_map> 
using namespace std; 
typedef pair<int, pair<int, int> > ppi;

void k_frequent(int arr[], int n, int k){
	unordered_map<int, int> mp;

	priority_queue<pair<int, int>,vector<pair<int, int> >,greater<pair<int, int> > > min_heap;
	vector<int> sub;
	for (int i = 0; i < n; ++i)
		{
			//store pair of arr[i] and freq in mp
			mp[arr[i]]++;
		}

	for(auto i :mp){
		//store freq and arr[i] in heap. sorted acc to freq. max will be at the bottom. bottom k will be final ans
		 min_heap.push(make_pair(i.second, i.first));
		 if(min_heap.size()>k){
		 	min_heap.pop();
		 }
	}

	cout<<"Number"<<'\t'<<"FREQ"<<endl;
	while(!min_heap.empty()){
		cout<<min_heap.top().second<<"\t"<<"\t"<<min_heap.top().first<<endl;
		min_heap.pop();
	}
	return;
}


int main(){

	int arr[]={1,1,1,3,2,2,4};
	int n=sizeof(arr)/sizeof(arr[0]);
	int k=2;
	k_frequent(arr,n,k);

	return 0;
}