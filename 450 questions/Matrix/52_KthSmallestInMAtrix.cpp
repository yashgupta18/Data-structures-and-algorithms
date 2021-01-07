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
#define logarr(arr,a,b)	for(int z=(a);z<(b);z++) cout<<(arr[z])<<" ";cout<<endl;	

#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
// mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define M 4 
#define N 4
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


int kSmallest(int mat[M][N], int k){
	//declare min heap with (int , (i,j)) structure
	priority_queue< pair<int,pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int,pair<int, int> > > > min_heap;
	
	//insert first column
	for (int i = 0; i < N; ++i)
	{
		/* code */
		min_heap.push(make_pair(mat[i][0], make_pair(i,0)));

	}
	int count=7, ans;

	// keepinserting next column element of current top and pop
	while(count--){
		int tempi=min_heap.top().second.first;
		int tempj=min_heap.top().second.second;
		ans=min_heap.top().first;
		min_heap.pop();
		min_heap.push(make_pair(mat[tempi][tempj+1], make_pair(tempi, tempj+1)));
	}

	return ans;
	
}


int32_t main()
{
    clock_t begin = clock();

    //EXPLAINATION:  https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/2471/Very-concise-O(log(min(MN)))-iterative-solution-with-detailed-explanation
   int mat[M][N] = { {10, 20, 30, 40}, 
                    {15, 25, 35, 45}, 
                    {24, 29, 37, 48}, 
                    {32, 33, 39, 50}, 
                };  
  	int k=7;
    cout<<kSmallest(mat, k);  

	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 

    return 0;
}