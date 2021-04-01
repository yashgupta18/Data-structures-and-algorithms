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
	    if(n==2 || n%2!=0){
	    	cout<<"NO"<<endl;
	    }
	    else{
	    	int arr[n];
	    	ll j=2;
	    	for(int i=0; i<n/2;i++){
	    		arr[i]=j;
	    		j+=2;
	    	}
	    	j=1;
	    	for (int i = (n/2)+1; i < n; ++i)
	    	{
	    		/* code */
	    		arr[i]=j;
	    		j+=2;
	    	}
	    }

	    for (int i = 0; i < n; ++i)
	    {
	    	/* code */
	    	cout<<arr[i]<<" ";
	    }
	    cout<<endl;
	    
	}
	return 0;
}


