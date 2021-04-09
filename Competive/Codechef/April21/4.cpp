#include<iostream>

#define ll  long long int
using namespace std;

int main()
{
	int tc;
	cin>>tc;
	while(tc--){
		ll n;
		cin>>n;
		ll ans=0;
		if(n==1){
			ans=20;
		}else if(n==2){
			ans=36;
		}
		else if(n==3){
			ans=51;
		}
		else if(n==4){
			ans=60;
		} 
		else if(n>4){
			ll a=n%4;
			ll q=n/4;
			if(a==1){
				ans=(60*q+20-4*(n-4));
			}else if(a==2){
				ans=(60*q+36-4*(n-4));
			}else if(a==3){
				ans=(60*q+51-4*(n-4));
			}else if(a==0){
				ans=(60*q+0-4*(n-4));
			}
		}

		cout<<ans<<endl;
	}
    return 0;
}






