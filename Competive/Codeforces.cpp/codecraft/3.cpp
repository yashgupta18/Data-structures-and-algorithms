#include <iostream>
#include <string>

#define ll long long int
using namespace std;



int main() {
	// your code goes here
	ll tc;
	cin>>tc;
	while(tc--){
	    ll n,k;
	    cin>>n>>k;
	    ll sum=0;
	    if(k==1 || (n==1 && k==1)){
	    	cout<<1<<endl;
	    }else if(n==1 && k>1){
	    	cout<<2<<"dff"<<endl;
	    }else{
	    	sum+=2;
	    	n--;
	    	while(n>0){
	    		sum=sum*(n-1);
	    		n--;
	    	}
	    	cout<<sum<<endl;
	    }


	    
	}
	return 0;
}


