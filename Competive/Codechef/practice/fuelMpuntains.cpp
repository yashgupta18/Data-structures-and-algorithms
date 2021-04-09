#include <iostream>
#define ll long long int
using namespace std;
int main() {
	// your code goes here
	ll tc;
	cin>>tc;
	while(tc--){
	    int n;
	    cin>>n;
	    if(n==0) cout<<0<<"\n"<<break;
	    int arr[n];

	    for (int i = 0; i < n; ++i)
	    {
	    	cin>>arr[i];
	    }

	    int max_so_far = INT_MIN, max_ending_here = 0;
 
	    for (int i = 0; i < n; i++)
	    {
	        max_ending_here = max_ending_here + arr[i];
	        if (max_so_far < max_ending_here)
	            max_so_far = max_ending_here;
	 
	        if (max_ending_here < 0)
	            max_ending_here = 0;
	    }

	    cout<<max_so_far<<"\n";
	    
	}
	return 0;
}

