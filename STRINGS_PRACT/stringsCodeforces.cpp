#include <iostream>
#include <string>

#define ll long long int
using namespace std;
int main() {
	ll tc;
	cin>>tc;
	while(tc--){
	    string s;
	    ll n,k;
	    cin>>n>>k;
	    cin>>s;
	    ll arr[26];
	    for(int i=0; i<26; i++){
	    	arr[s[i]]++;
	    	count++;
	    }

	    bool ans=true;
	    for(int i=0;i<26; i++){
	    	if(arr[i]/k!=0){
	    		ans=false;
	    		break;
	    	}
	    }

	    if(ans==true) return s;
	    else{
	    	
	    }
	}
	return 0;
}
