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
// #include <boost/functional/hash.hpp> 
#include <stack>
#include <map>
#include <unordered_map>
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
#define as(arr)         sizeof(arr)/sizeof(arr[0]);
#define pb              push_back
#define pii             pair<ll,ll>
#define vi              vector<ll>
#define vs				vector<string>
#define mii             map<int,int>
// #define mp 				make_pair
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
struct hashfunc
{
	size_t operator() (const pair<int,int>& l) const
	{ 
		return l.first ^ l.second; 
	}	
};

int gcd(int a, int b){
    if (b == 0)
       return a;
    return gcd(b, a % b); 
}

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

int maxPointOnSameLine(vector< pair<int, int> > points){
	unordered_map< pair< int,int >,int,hashfunc > mp;
	int n=points.size(), result=0, count=0, overlap=0, verticalPoints=0;
	loop(i,0,n){
		count=0, overlap=0, verticalPoints=0;
		
		loop(j,1,n){
			if(points[j].second==points[i].second && points[j].first==points[i].first)
				overlap++;

			else{
				int dx=points[j].second-points[i].second;
				int dy=points[j].second- points[i].first;
				int g=gcd(dx, dy);
				dx/=g;
				dy/=g;
				mp[make_pair(dx,dy)]++;
				count=max(count, mp[make_pair(dx,dy)]);
			}
		}
		count=max(count, verticalPoints); 
	}
	result=max(result, count+overlap+1);
	return result;
}

int32_t main()
{
    clock_t begin = clock();
    // https://www.geeksforgeeks.org/count-maximum-points-on-same-line/
    const int N = 6; 
    int arr[N][2] = {{-1, 1}, {0, 0}, {1, 1}, 
                    {2, 2}, {3, 3}, {3, 4} }; 
  
    vector< pair<int, int> > points; 
    for (int i = 0; i < N; i++) 
        points.push_back(make_pair(arr[i][0], arr[i][1])); 
  
    cout << maxPointOnSameLine(points) << endl; 

	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 

    return 0;
}