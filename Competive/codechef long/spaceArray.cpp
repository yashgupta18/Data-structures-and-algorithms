#include <iostream>
#include <unordered_map>
#define ll  long long
using namespace std;

string solve(ll n, ll arr[]){
    if(n==1 && arr[0]>1) return "Second";
    if(n==1 && arr[0]==1) return "First";
    
    sort(arr, arr+n);
    string ans="Second";
    int i=0;
    while(i<n){
        if(arr[i]==i+1){
            i++;
        }
        else{
            if(arr[i]<i+1){
                arr[i]=arr[i]+1;
                if(ans=="First"){
                    ans="Second";
                }else{
                    ans="First";
                }
            }
            else{
                return ans;
            }
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