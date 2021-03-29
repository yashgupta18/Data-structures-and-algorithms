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
        ll n,m,f=1, cnt=0,tmp;
        cin>>n>>m;
        vector<ll> v;
       
        map<ll,ll> mp;
        for (int i = 0; i < n; ++i)
        {
            /* code */
            cin>>tmp;
            mp[tmp]++;
            v.push_back(tmp);
        }

        for (int i = 0; i < n; ++i)
        {
            /* code */
            cin>>tmp;
            mp[tmp]=0;
            v.push_back(tmp);

        }

        sort(v.begin(), v.end());
        for(auto i: v){
            if(mp[i]!=f){
                if(f==1){
                    f=0;
                }else{
                    f=1;
                }
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }   
    return 0;
}




