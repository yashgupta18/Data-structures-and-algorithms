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



int32_t main()
{
    ll tc;
    ll m=1000000007;
    cin>>tc;
    while(tc--){
        ll n;
        cin>>n;
        ll x=2;
        ll y=n-1;
        ll temp=1;
        while(y>0){
            if(y%2==1){
                temp=(x*temp)%m;
            }
            x=(x*x)%m;
            y=y/2;
        }
        // ll ans=pow(2, n-1);
        cout<<temp<<endl;
    }

    return 0;
}




