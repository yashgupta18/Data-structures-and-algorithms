#include <iostream>
#include <string>

#define ll long long int
using namespace std;

string solve(ll n, string s, ll k){
	if((2*k)+1>n) return "NO";

	ll l = 0; 
    ll h = n-1;
    while (k>=0) 
    { 
        if (s[l] != s[h]) 
        { 
            return "NO"; 
        }
        l++;
        h--;
        k--; 
    }
    return "YES";
}

int main() {
	ll tc;
	cin>>tc;
	while(tc--){
	    string s;
	    ll n,k;
	    cin>>n>>k;
	    cin>>s;
	    cout<<solve(n, s, k)<<"\n";
	}

	return 0;
}

