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
#define M 5 
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


int findPair(int mat[M][N]){
	int ans=INT_MIN;
	int maxval=mat[M-1][N-1];
	int maxMat[M][N];
	maxMat[M-1][N-1]=mat[M-1][N-1];

	for (int i = N-1; i >=0; --i)
	{
		/* code */
		if(mat[M-1][i]>maxval){
			maxval=mat[M-1][i];
		}
		maxMat[M-1][i]=maxval;
	}
	
	maxval=mat[M-1][N-1];
	for (int i = M-1; i >=0; --i)
	{
		/* code */
		if(mat[i][N-1]>maxval){
			maxval=mat[i][N-1];
		}
		maxMat[i][N-1]=maxval;
	}

	for (int i = M-2; i >=0 ; --i)
	{
		/* code */
		for (int j = N-2; j >=0; --j)
		{
			/* code */
			if(maxMat[i+1][j+1]-mat[i][j] > ans){
				ans=maxMat[i+1][j+1]-mat[i][j];
			}

			maxMat[i][j]=max(mat[i][j], max(maxMat[i+1][j], maxMat[i][j+1]));
		}
	}

	for (int i = 0; i < M; ++i)
	{
		/* code */
		for (int j = 0; j < N; ++j)
		{
			/* code */
			cout<<maxMat[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<endl;
	return ans;

}


int32_t main()
{
    clock_t begin = clock();

    //EXPLAINATION:  https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/2471/Very-concise-O(log(min(MN)))-iterative-solution-with-detailed-explanation
   int mat[M][N] = {{ 1, 2, -1, -4, -20 },
             { -8, -3, 4, 2, 1 }, 
             { 3, 8, 6, 1, 3 },
             { -4, -1, 1, 7, -6 },
             { 0, -4, 10, -5, 1 }};

    int ans=findPair(mat);  
    cout<<"Ans="<<ans;
	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 

    return 0;
}