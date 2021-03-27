#include <iostream>
#include <string>
#include <vector>
#define ll long long int
using namespace std;
// https://www.codechef.com/LTIME94C/problems/IMDB

int main() {
	// your code goes here
	ll tc;
	cin>>tc;
	while(tc--){
	    int n,x;
	    cin>>n>>x;

	    int maxI=0, ans=0;
	    for (int i = 0; i < n; ++i)
	    {
	    	/* code */
	    	int s,r;
	    	cin>>s>>r;
	    	if(r>maxI && s<=x){
	    		maxI=r;
	    	}
	    }

	    cout<<maxI<<endl;

	    
	}
	return 0;
}

