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
		bool ans=false;
	    ll n,k1,k2,w,b;
	    cin>>n>>k1>>k2;
	    cin>>w>>b;
	    int wA=k1+k2;
	    int bA=(2*n) - wA;
	    if(wA>=2*w && bA>=2*b) ans=true;
	    else ans=false;
	    if(ans) cout<<"YES\n";
	    else cout<<"NO\n";
	}
	return 0;
}


