#include<iostream>
#include<vector>
#include<queue>

using namespace std;
// Q. https://codeforces.com/contest/1491/problem/A

int main(){
	int n,q;
	cin>>n>>q;
	int arr[n];
	// int temp[n];
	for (int i = 0; i < n; ++i)
	{
		/* code */
		cin>>arr[i];
	}

	for (int i = 0; i < q; ++i)
	{
		/* code */
		int t, query;
		cin>>t>>query;
		if(t==1){
			arr[query-1]=1-arr[query-1];
		}
		if(t==2){
			priority_queue<int,vector<int>,greater<int> > mh;
	        
	        for (int i = 0; i < n; ++i){
	           mh.push(arr[i]);
	            if(mh.size()>query){
	                mh.pop();
	            }
	        }
			cout<<mh.top()<<"\n";
			while(!mh.empty()){
				mh.pop();
			}
		}
	}
}