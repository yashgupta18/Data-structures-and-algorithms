#include <iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<string>
#include<cstring>
#include<bitset>
#include<regex>
#define int int64_t
using namespace std;
// https://codeforces.com/problemset/problem/478/B

int32_t main(){
	int n, k;
	cin>>n>>k;
	if(k==1){
        long long ans=(n*(n-1))/2;
        cout<<ans<<" "<<ans<<"\n";
    }
    else{
	    int maxi=((n-k+1)*(n-k))/2;
	    int other1=n/k;
	    int other2=n%k;
	    int ans1=(other1*(other1-1))/2;
	    int ans2=((other1+1)*(other1))/2;
	    int ans3=(ans1*(k-other2))+(ans2*(other2));
	    cout<<ans3<<" "<<maxi<<"\n";
	}
	
	return 0;
}