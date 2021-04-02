#include<iostream>
#include <iomanip>      // std::setprecision
#define ll  long long int
using namespace std;

int main()
{
	ll tc;
	cin>>tc;
	while(tc--){
		ll n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		ll maxsofar=0, temp=0;
		bool ans=false;
		for (int i = 0; i < n; ++i)
		{
			if(s[i]=='*'){
				temp++;
			}else{
				temp=0;
			}
			maxsofar=max(maxsofar,temp);
			if(maxsofar>=k){
				ans=true;
				break;
			}
		}
		if(ans==true || maxsofar>=k){
			cout<<"YES\n";
		}else{
			cout<<"NO\n";
		}
	}
    return 0;
}






