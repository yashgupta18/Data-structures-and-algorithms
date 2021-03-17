#include <iostream>
#include <queue>

#define ll long long int
using namespace std;
int main() {
	// your code goes here
	
	    ll n, q;
	    cin>>n>>q;
	    int arr[n];
	    for (int i = 0; i < n; ++i)
	    {
	    	cin>>arr[i];
	    }

	    for(int i=n-1; i>0; i--){
	    	arr[i]=arr[i]-arr[i-1];
	    }

	    queue< pair<int, pair<int, int> > > qu; 
	    for (int j = 0; j < q; ++j)
	    {
	    	/* code */
	    	ll l,r,i;
	    	cin>>l>>r>>i;
	    	
	    	qu.push(make_pair(l-1, make_pair(r-1, i))); 
	    }

	    
	    

	    while(!qu.empty()){
	    	ll l=qu.front().first;
	    	ll r=qu.front().second.first;
	    	ll i=qu.front().second.second;
	    	qu.pop();

	    	// cout<<l<<" "<<r<<" "<<i<<endl;
	    	for (int j = l; j<=r ; ++j)
	    	{
	    		/* code */
	    		arr[j]=arr[j]-i;
	    	}
	    }

	    for (int i = 0; i < n; ++i)
	    {
	    	/* code */
	    	cout<<arr[i]<<" ";
	    }
	    cout<<"\n";

	return 0;
}




