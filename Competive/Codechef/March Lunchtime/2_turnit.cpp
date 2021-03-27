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
	    	int ans=pow(u,2)-(2*a*s);
		    double final=sqrt(ans);
		    if(ans<=v){
		    	cout<<"YES"<<endl;
		    }
		    else{
		    	cout<<"No"<<endl;
		    }
	    }
	}
	return 0;
}

