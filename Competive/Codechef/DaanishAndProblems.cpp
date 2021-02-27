#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;
 
#define ll  long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int solve(){
	fastio
	ll n=10;
	ll arr[10];
	for(ll i=0; i<n; i++){
		cin>>arr[i];
	}
	ll k;
	cin>>k;
	ll ans=0;

	for(ll i=n-1; i>=0; i--){
		if(arr[i]<=k){
			// ans=i;
			ll temp=arr[i];
			arr[i]=0;
			k=k-temp;
		}
	}

	for(ll i=n-1; i>=0; i--){
		if(arr[i]!=0){
			ans=i;
			ans++;
			break;
		}
	}

	// cout<<endl;
	return ans;
}


int main()
{ 

	ll tc;
    cin>>tc;
    while(tc--){
    	int ans=solve();
        cout<<ans<<"\n";cout.flush();
    }

    return 0;
}