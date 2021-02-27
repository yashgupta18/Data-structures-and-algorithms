#include <iostream>
#include <string>

#define ll long long int
using namespace std;
// Q. https://www.codechef.com/problems/PALPALS
int main() {
	// your code goes here
	ll tc;
	cin>>tc;
	while(tc--){
	    string s;
	    cin>>s;
	    vector<ll> freq(26);
	    for(auto i:s){
	        freq[i-'a']++;
	    }
	    ll single=0, couple=0;
	    for(auto i:freq){
	        if(i==1){
	            single++;
	        }
	        if(i%2==0){
	            couple+=i/2;
	        }
	        if(i>3 && i&1){
	            couple+=(i-3)/2;
	        }
	    }
	    if(single<=couple) cout<<"YES"<<endl;
	    else cout<<"NO"<<endl;
	}
	return 0;
}
