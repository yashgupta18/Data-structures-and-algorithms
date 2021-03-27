#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
// https://www.codechef.com/LTIME94C/problems/LUNCHTIM
#define ll long long int
using namespace std;
int main() {
	// your code goes here
	ll tc;
	cin>>tc;
	while(tc--){
	    ll n;
	    cin>>n;
	    ll arr[n];
	    // ll ans[n];
	    for (int i = 0; i < n; ++i)
	    {
	    	cin>>arr[i];
	    }
	    
	   
	    for (int i = 0; i < n; ++i)
	    {
	    	int cnt=0;
	    	for (int j = i-1; j >=0 ; --j)
	    	{
	    		/* code */
	    		if(arr[j]>arr[i])break;
	    		else if(arr[j]==arr[i]){
	    			cnt++;
	    		}
	    	}

	    	for (int j = i+1; j < n; ++j)
		    {
		    	if(arr[j]>arr[i]) break;
		    	else if(arr[j]==arr[i]){
		    		cnt++;
		    	}
		    }
		    cout<<cnt<<" ";
	    }

	    cout<<endl;

	    
	}
	return 0;
}

