#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;
 
#define ff              first
#define ss              second
#define ll             long long
// #define ll              long long int
#define ld              long double
#define endl            "\n"
#define as(arr)         sizeof(arr)/sizeof(arr[0]);
#define pb              push_back
#define pii             pair<ll,ll>
#define vi              vector<ll>
#define vs              vector<string>
#define mii             map<int,int>
#define mp              make_pair
#define all(n)          n.begin(),n.end()
#define ump             unordered_map
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define loop(i,a,b)     for(int i=(a);i<=(b);i++)
#define looprev(i,a,b)  for(int i=(a);i>=(b);i--)
#define iter(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define mid(l,r)        (l+(r-l)/2)
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define logarr(arr,a,b) for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;   

#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)

int isSafe(int p,int q, int x1, int y1, int x2, int y2){
	if(p>=x1 && q>=y1 && p<=x2 && q<=y2) return true;
	return false;
}

int32_t main()
{
    ll tc;
    cin>>tc;
    while(tc--){
        ll x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        int mat[x2+3][y2+3];
        mat[1][1]=1;
        int t=1;
        for (int i = 2; i <=y2+2 ; ++i)
        {
        	mat[1][i]=mat[1][i-1]+t;
        	t++;
        }
        for (int i = 2; i <=x2+2; ++i)
        {
        	for (int j = 1; j <=y2+2; ++j)
        	{	
        		mat[i][j]=mat[i-1][j+1]+1;
        	}
        }

        int sum=0, p=x1,q=y1;
       	while(p!=x2){
       		sum+=mat[p][q];
       		p++;
       	}
       	if(p==x2 && q==y2){
       		cout<<sum<<endl;
       	}
       	else{
       		while(q!=y2){
	       		sum+=mat[p][q];
	       		q++;
	       	}
	       	if(q==y2){
	       		sum+=mat[p][q];
	       	}
	       	cout<<sum<<endl;
       	}

        
        

    }

    return 0;
}




