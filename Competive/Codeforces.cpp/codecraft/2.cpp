// #include <bits/stdc++.h>
#include <iostream>
#define ll long long int
using namespace std;
int main() {
	// your code goes here
	ll tc;
	cin>>tc;
	while(tc--){
	    ll n,W;
	    cin>>n>>W;
	    ll arr[n];
	    for (int i = 0; i < n; ++i)
	    {
	    	/* code */
	    	cin>>arr[i];
	    }
	    // sort(arr, arr+n);
	    ll j=0,h=1;
	    ll w=W;
	    for (int i = 0; i < n; ++i)
	    {
	    	if(w-arr[i]<0){
	    		h++;
	    		w=W;
	    	}
	    	else{
	    		w=w-arr[i];
	    		cout<<w<<endl;
	    	}
	    }
	   	cout<<h;
	   	cout<<'\n';
	    
	}
	return 0;
}