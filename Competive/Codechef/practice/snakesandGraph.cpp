#include<iostream>
#include <vector>
#define ll  long long int
using namespace std;

int main()
{
    ll tc;
    cin>>tc;
    while(tc--){

        ll x, y, nodes, edges;
        ll arr[nodes+1];
        memset(arr, 0, sizeof(arr));
        cin >> nodes>>edges; 

        vector <ll> adj[nodes+1];      //Number of edges
        for(ll i = 0;i < edges;++i)
        {
                cin >> x >> y;
                adj[x].push_back(y);     
                adj[y].push_back(x);   
                int count1=adj[x].size();
                int count2=adj[y].size();
                arr[x]=count1;
                arr[y]=count2;
        }

        // for(ll i = 1;i <=nodes;++i)
        // {   
        //     int count=adj[i].size();
        //     arr[i]=count;
        // }


        // for (int i = 0; i <=nodes; ++i)
        // {
        //      code 
        //     cout<<arr[i]<<" ";
        // }
        // cout<<endl;

        // for(ll i = 1;i <=nodes;++i)
        // {   
        //     cout << "Adjacency list of node " << i << ": ";
        //     for(ll j = 0;j < adj[i].size();++j)
        //     {
        //         if(j == adj[i].size() - 1)
        //                 cout << adj[i][j] << endl;
        //         else
        //             cout << adj[i][j] << " --> ";
        //     }
        // }
        map<ll,ll> mp;
        for(ll j = 1; j<=nodes ;++j){
            mp[adj[j].size()]++;
        }
        vector<ll> ans;
        for (int i = 0; i <nodes; ++i)
        {
            int count=0;
            // for(ll j = 1; j<=nodes ;++j){
                if(mp[]<=i){
                    count++;
                }
            // }
            if(count==nodes){
                count=count-1;
            }
            ans.push_back(count);
        }

        for (int i = 0; i < ans.size(); ++i)
        {
            /* code */
            cout<<ans[i]<<" ";
        }


    }
    
    return 0;
}






