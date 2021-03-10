#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <algorithm>

#define ll long long int
using namespace std;



int main() {
	ll tc;
	cin>>tc;
	while(tc--){
	    ll n,k;
	    cin>>n>>k;
	    unordered_map<int, int> mp;
	    ll uniq=0;
	    ll maxE=INT_MIN;
	    for (ll i = 0; i < n; ++i)
	    {
	    	ll ele;
	    	cin>>ele;
	    	mp[ele]++;
	    	maxE=max(maxE, ele);
	    	
	    	if(mp[ele]==1){
	    		uniq++;
	    	}
	    }

	   	ll mex=INT_MAX;

	    for (int i = 0; i <= maxE+1; ++i)
	    {
	    	if(!mp[i]){
	    		mex=i;
	    		break;
	    	}
	    }
	    if(maxE>mex && k!=0){
	    	ll avg= ((maxE+mex+1)/2);
	    	mp[avg]++;
	    	if(mp[avg]==1){
	    		uniq++;
	    	}
	    }

	    else if(mex>maxE && k!=0){
	    	uniq=uniq+k;
	    }


	     
	    cout<<uniq<<"\n";
	}
	return 0;
}


