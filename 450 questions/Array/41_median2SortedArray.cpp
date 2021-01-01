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
#define int             long long
#define ll 				long long int
#define ld				long double
#define endl			"\n"
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


int medianFind(int arr1[], int arr2[], int m, int n){
	int low=0, high=n*2;

	while(low<=high){
		// Get L1, R1, L2, R2 respectively
		int mid2=(low+high)/2;
		int mid1=m+n-mid2;
		int L1=(mid1==0)? INT_MIN : arr1[(mid1-1)/2];
		int L2=(mid1==0)? INT_MIN : arr2[(mid2-1)/2];
		int R1=(mid2==m*2)? INT_MAX : arr1[(mid1)/2];
		int R2=(mid2==n*2)? INT_MAX :arr2[(mid2)/2];

		if(L1>R2) {
			// Arr1's lower half is too big; need to move C1 left (C2 right)
			low=mid2+1;
		}

		else if(L2>R1){
			// Arr2's lower half is too big; need to move C2 left
			high=mid2-1;
		}
		else{
			// that's the right cut.
			return (max(L1,L2) + min(R1, R2))/ 2;
		}
	}
	return -1;
}


int32_t main()
{
    clock_t begin = clock();

    //EXPLAINATION:  https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/2471/Very-concise-O(log(min(MN)))-iterative-solution-with-detailed-explanation
    int arr1[] = {10, 12, 14, 16, 18, 20};
    int arr2[] = {2, 3, 5, 8};
    int m=sizeof(arr1)/sizeof(arr1[0]);
    int n=sizeof(arr2)/sizeof(arr2[0]);
    cout<<medianFind(arr1, arr2, m,n);

	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 

    return 0;
}