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
// #define int             long long
#define ll 				long long int
#define ld				long double
#define endl			"\n"
#define as(arr)         sizeof(arr)/sizeof(arr[0]);
#define pb              push_back
#define pii             pair<ll,ll>
#define vi              vector<ll>
#define vs				vector<string>
#define mii             map<int,int>
#define mp 				make_pair
#define all(n) 			n.begin(),n.end()
#define ump				unordered_map
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define iter(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define mid(l,r)        (l+(r-l)/2)
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;	

#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
// mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
 
void file_i_o()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
}

int gethero(){
	int n, arr[n];
		cin>>n;
		// n=read(int);
		for (int i = 0; i < n; ++i)
		{
			/* code */
			cin>>arr[i];
		}
 
		// if(n==2 && arr[0]==arr[1]) return 0;
		sort(arr, arr+n);
		for (int i = 0; i < n; ++i)
		{
			/* code */
			// cout<<arr[i]<<" ";
		}
		int count=0;
		for (int i = 1; i < n; ++i)
		{
			/* code */
			if(arr[i]>arr[i-1]){
				return n-i;
			}
		}
 
		return 0;
}
 
int32_t main()
{
    clock_t begin = clock();
    // file_i_o();
	// Write your code here....
 
	int tc;
	cin>>tc;
	// tc = read(int);
 
	while(tc--){
		cout<<gethero();
	}
		// return count-1;
 
	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
 
    return 0;
}



