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
#include <unordered_set>
#include <unordered_map>
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
#define int             long long
#define ll 				long long int
#define ld				long double
// #define endl			"\n"
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
#define logarr(arr,a,b)	for(int z=(a);z<(b);z++) cout<<(arr[z])<<" ";cout<<endl;	

#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
// mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define M 6 
#define N 5
// struct compare
// {
//     bool operator()(const pair<int,pair<int, int> >& a, const pair<int,pair<int, int> >& b)
//     {
//         return a.first>b.first;
//     }
// };

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


void spiralPrint(int mat[M][N]){
	int r=0,l=M-1, c=0, m=N-1;
	while(r<=l && c<=m){
		for (int i=c ; i <= m; ++i)
		{
			/* code */
			cout<<mat[r][i]<<" ";
			// cout<<r<<" "<<i<<"  ";
		}
		r++;
		cout<<endl;
		for (int i = r; i <= l; ++i)
		{
			/* code */
			cout<<mat[i][m]<<" ";
			// cout<<i<<" "<<m<<"  ";
		}
		m--;
		cout<<endl;
		for (int i = m; i >= c; --i)
		{
			cout<<mat[l][i]<<" ";
			// cout<<l<<" "<<i<<"  ";
		}
		l--;
		cout<<endl;
		for (int i = l; i >= r; --i)
		{
			cout<<mat[i][c]<<" ";
			// cout<<i<<" "<<c<<"  ";
		}
		c++;
		cout<<endl;
	}
}


int32_t main()
{
   int mat[M][N] = {{ 1, 2, 1, 4, 20 },
             		{ 8, 3, 4, 2, 1 }, 
             		{ 3, 8, 6, 1, 3 },
             		{ 4, 1, 1, 7, 6 },
             		{ 0, 4, 10, 5, 1 },
             		{ 5, 8, 12, 1, 3},
             	};

    spiralPrint(mat);  

    return 0;
}