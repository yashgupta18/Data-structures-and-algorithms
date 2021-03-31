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
	    ll n,m,x;
	    cin>>n>>m>>x;
	    // int colMat[100005][100005];
	    // int rowMat[100005][100005];
	    int p=1;
	    int r,c;
	    for (int i = 0; i < m; ++i)
	    {
	    	/* code */
	    	for (int j = 0; j < n; ++j)
	    	{
	    		/* code */
	    		// colMat[j][i]=p;
	    		
	    		if(p==x){
	    			cout<<"p="<<p<<endl;
	    			r=j;
	    			c=i;
	    			goto end;
	    		}
	    		p++;
	    	}
	    }

	    end:
	    int q=1;
	    for (int i = 0; i < n; ++i)
	    {
	    	for (int j = 0; j < m; ++j)
	    	{
	    		/* code */
	    		if(i==r && j==c){
	    			cout<<q<<endl;
	    			break;
	    		}
	    		q++;
	    	}
	    }
	    
	}
	return 0;
}


