#include <iostream>
#include <unordered_map>
#define ll  long long
using namespace std;

string solve(ll n, ll arr[]){
	unordered_map<int, int> count; 
    for (int i = 0; i < n; i++) 
        count[arr[i]]++; 
    string ans="First";
    for (int i = 0; i < n; ++i)
    {
        /* code */
        if(arr[i]!=i){
            for(auto x: count){
                if(x.second>1){
                    count[x]--;
                }
            }
            arr[i]=i;
            count[i]++;
            ans="Second";
        }
    }
    return ans;

}

int main()
{
    ll tc;
    cin>>tc;
    while(tc){
        ll N;
        cin>>N;
        ll arr[N];
        for (ll i = 0; i < N; ++i)
        {
            cin>>arr[i];
        }

        cout<<solve(N,arr)<<"\n";
        tc--;
    }
	

    return 0;
}