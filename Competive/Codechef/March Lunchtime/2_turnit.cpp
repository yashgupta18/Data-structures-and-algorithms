#include <iostream>
#include <cmath>

#define ll long long int
using namespace std;
// https://www.codechef.com/LTIME94C/problems/NFS
int main() {
	// your code goes here
	ll tc;
	cin>>tc;
	while(tc--){
	    ll u,v,a,s;
	    cin>>u>>v>>a>>s;
	    if(u<=v){
	    	cout<<"YES"<<endl;
	    }
	    else{
		    if((u*u-v*v)<=2*a(s)){
		    	cout<<"YES"<<endl;
		    }
		    else{
		    	cout<<"No"<<endl;
		    }
	    }
	}
	return 0;
}

