#include <iostream>
#define ll  long long
using namespace std;

string solve(ll N, ll H, ll x, ll arr[]){
	for(ll i=N; i>=0; i--){
    	if(arr[i]+x>=H){
    		return "YES";
    	}
    }
    return "NO";
}

int main()
{
	ll N,H,x;
    cin>>N>>H>>x;
    ll arr[N];
    for (ll i = 0; i < N; ++i)
    {
    	/* code */
    	cin>>arr[i];
    }

    cout<<solve(N,H,x,arr)<<"\n";

    return 0;
}