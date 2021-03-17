#include <iostream>
#include <string>
#define ll long long int
using namespace std;

string s1, s2;
ll k;

void solve(string s1,string s2, int k){
		ll n=s1.length();
	    ll m=s2.length();
	    if(n==0 || m==0) {
	    	cout<<"LOSE"<<"\n";
	    	return;
	    }

	    ll sum1=0, sum2=0;
	    for(int i=0;i<n; i++){
	    	sum1=sum1+s1[i];
	    }
	    for(int i=0;i<m; i++){
	    	sum2=sum2+s2[i];
	    }

	    if(sum1!=sum2){
	    	cout<<"LOSE"<<"\n";
	    	return;
	    }

	    ll i=0,j=0;
	    while(i<n && j<m){
	    	if(abs(s1[i]-s2[j])>k){
	    		cout<<"LOSE"<<"\n";
	    		return;
	    	}
	    	i++;
	    	j++;
	    }

	    cout<<"WIN"<<"\n";
	    return;

}


int main() {
	int t;
    scanf("%d",&t);
    while(t--){
        cin >> s1 >> s2;
        cin>>k;
        solve(s1, s2, k);
	}

	return 0;
}
