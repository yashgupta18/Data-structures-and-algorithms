#include <iostream>
#include <string>

#define ll long long int
using namespace std;
// https://www.codechef.com/LTIME94C/problems/MKSMEVN
int main() {
	// your code goes here
	ll tc;
	cin>>tc;
	while(tc--){
	    ll n;
	    cin>>n;
	    ll arr[n];
	    ll sum=0;
	    for (ll i = 0; i < n; ++i)
	    {
	    	cin>>arr[i];
	    	sum+=arr[i];
	    }

	    if(sum%2==0){
	    	cout<<0<<endl;
	    }
	    else{
	    	int ans=0;
	    	for (int i = 0; i < n; ++i)
	    	{
	    		/* code */
	    		if(arr[i]%2==0 && ((arr[i]/2)-1<=0)){
	    			ans=1;
	    			break;
	    		}
	    	}
	    	if(ans==0){
	    		cout<<-1<<endl;
	    	}else{
	    		cout<<1<<endl;
	    	}
	    }

	    
	}
	return 0;
}

