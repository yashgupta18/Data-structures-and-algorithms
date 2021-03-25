#include <iostream>
#include <cmath>
#include <queue>
#include <utility>
#include <iomanip>      // std::setprecision
#include <algorithm>

#define ll long long int
using namespace std;


int main() {
	ll tc;
	cin>>tc;
	while(tc--){
        int n,k;
        cin>>n>>k;
	    string s;
	    cin>>s;
        int p,q;
	    for (int i = 0; i < n; ++i)
        {
            /* code */
            if(s[i]=='*'){
                p=i;
                break;
            }
        }

        for (int j = n-1; j>=0; j--)
        {
            /* code */
            if(s[j]=='*'){
                q=j;
                break;
            }
        }

        if(p==q){
            cout<<1<<endl;
        }
        else if(q-p<=k){
            cout<<2<<endl;
        }
        else{
            cout<<3<<endl;
        }
	}
	return 0;
}


