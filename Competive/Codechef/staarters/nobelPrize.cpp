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

#define ll  long long int
using namespace std;

int main()
{ 
    ll tc;
    cin>>tc;
    while(tc--){
        ll n,m, t,prev=0,flag=0;
        cin>>n>>m;
        ll arr[n];
        set<ll> s;
        for (int i = 0; i <n; ++i)
        {
            /* code */
            
            cin>>arr[i];
            s.insert(arr[i]);
        }

        if(m>s.size()){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }   
    return 0;
}