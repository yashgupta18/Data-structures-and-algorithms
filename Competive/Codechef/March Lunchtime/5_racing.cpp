#include <iostream>
#include <string>

#define ll long long int
using namespace std;
// https://www.codechef.com/LTIME94C/problems/RACINGEN
int main() {
	// your code goes here
	ll tc;
	cin>>tc;
	while(tc--){
	    ll y,p,k;
	    cin>>y>>p>>k;
	    if(y>= 60*p){
	    	if(p<=k){
	    		cout<<"YES"<<endl;
	    	}else{
	    		cout<<"NO"<<endl;
	    	}
	    }
	    else{
	    	if(y+2*(60*p-y)<=60*k){
	    		cout<<"YES"<<endl;
	    	} 
	    	else{
	    		cout<<"NO"<<endl;
	    	}
	    }

	    
	}
	return 0;
}

