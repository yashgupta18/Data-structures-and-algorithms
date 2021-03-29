#include<bits/stdc++.h>

#define ll unsigned long long
using namespace std;
// Q. https://www.codechef.com/problems/PALPALS
int main() {
	// your code goes here
	ll tc;
	cin>>tc;
	while(tc--){
	    ll n,no,gcdb=0;
	    cin>>n;
	    while(gcdb<=1){
	    	no=n;
	    	ll s=0;
	    	while(no){
	    		s+=no%10;
	    		no/=10;
	    	}
	    	gcdb=__gcd(n++,s);
	    }
	    cout<<n-1<<endl;
	}
	return 0;
}

