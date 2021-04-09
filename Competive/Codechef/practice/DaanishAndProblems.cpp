#include <iostream>
#define ll  long long
using namespace std;

int main()
{ 

	ll tc;
    cin>>tc;
    while(tc--){
        ll n=10;
		ll arr[10];
		for(ll i=0; i<n; i++){
			cin>>arr[i];
		}
		ll k;
		cin>>k;
		int i=9;
		while(k>=arr[i]){
			k=k-arr[i];
			i--;
		}
		cout<<i+1<<endl;

    }

    return 0;
}