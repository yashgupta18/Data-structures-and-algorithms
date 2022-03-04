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
    cin>>tc;
    while(tc--){
        char v[3][3];
        int x=0,o=0,d=0;
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                cin>>v[i][j];
                if(v[i][j]=='X') x++;
                else if(v[i][j]=='O')o++;
                else if(v[i][j]=='_')d++;
            }
        }
        
        int xwin=0,owin=0;
        for (int i = 0; i < 3; ++i)
        {
            if(v[i][0]==v[i][1] && v[i][2]==v[i][1]){
                if(v[i][0]=='X') xwin++;
                else if(v[i][0]=='O') owin++;
            }
        }

        for (int i = 0; i < 3; ++i)
        {
            if(v[0][i]==v[1][i] && v[2][i]==v[1][i]){
                if(v[0][i]=='X') xwin++;
                else if(v[0][i]=='O') owin++;
            }
        }

        if(v[0][0]==v[1][1] && v[2][2]==v[1][1]){
            if(v[1][1]=='X') xwin++;
            else if(v[1][1]=='O') owin++;
        }

        if(v[0][2]==v[1][1] && v[2][0]==v[1][1]){
            if(v[1][1]=='X') xwin++;
            else if(v[1][1]=='O') owin++;
        }
       

        if(o>x) cout<<3<<endl;
        else if(x-o>1) cout<<3<<endl;
        else if(x>o && xwin==1 && owin==0) cout<<1<<endl;
        else if(o==x && owin==1 && xwin==0) cout<<1<<endl;
        
        //special case
         // xox
        // oxo
        // xox
        else if(d==0 && xwin==2) cout<<1<<endl;
       
        else if(xwin+owin==0 && d==0) cout<<1<<endl;
        else if(d>0 && xwin+owin==0) cout<<2<<endl;

        else cout<<3<<endl;
    }

    return 0;
}




