#include <iostream>
#include <string>

#define ll long long int
using namespace std;
// https://www.codechef.com/LTIME94C/problems/DATE1
int main() {
	// your code goes here
	ll tc;
	cin>>tc;
	while(tc--){
	    ll m,n,p;
	    cin>>m>>n>>p;
	    if(m>=n){
	    	cout<<p*n<<endl;
	    }
	    else{
	    	cout<<p*m+1<<endl;
	    }

	    
	}
	return 0;
}

