#include <iostream>
#include <cmath>
#include <queue>
#include <utility>
#include <iomanip>      // std::setprecision
#include <algorithm>

#define ll long long int
using namespace std;



int main() {
	ll tc;
	cin>>tc;
	while(tc--){
	    ll n;
	    cin>>n;
	    ll arr1[n];
	    ll arr2[n];
	    // priority_queue<int, vector<int>, greater<int> > min_heap1;
	    // priority_queue<int, vector<int>, greater<int> > min_heap2;
	    ll m=0, o=0;
	    for (int i = 0; i < n*2; ++i)
	    {
	    	/* code */
	    	ll a, b;
	    	cin>>a>>b;
	    	if(a==0){
	    		arr2[m]=abs(b);
	    		m++;
	    	}
	    	if(b==0){
	    		arr1[o]=abs(a);
	    		o++;
	    	}

	    }
	    sort(arr1, arr1+n);
	    sort(arr2, arr2+n);
	    double ans=0;
	    for (int i = 0; i < n; ++i)
	    {
	    	ll x=arr1[i];
	    	ll y=arr2[i];
	    	ans+=sqrt((x*x*1.0) + (y*y*1.0));
	    }
	    cout<<setprecision(15)<<ans<<"\n";
	    
	}
	return 0;
}


