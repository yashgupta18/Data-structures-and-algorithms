
#include <iostream>
#include <vector>
#include <string>
#include <set>

#define ll long long int
using namespace std;

int solve(int n, int arr[]){
    set<int> ans;
    int myset[4]={2,3,5,7};
    for(int i=0;i<n;i++){
        for(int j=0; j<4; j++){
            if(arr[i]%myset[j]==0){
                ans.insert(myset[j]);
            }else{
                if(arr[i]%myset[j]!=0 && j==3){
                    ans.insert(arr[i]);
                }
            }
        }
    }

    int fans=1;
    for (auto elem : ans)
    {
        cout << elem << " , ";
    }
    return fans;
}

int32_t main()
{
    
    int N;
    cin>>N;
    int arr[N];
    for (int i = 0; i < N; ++i)
    {
        cin>>arr[i];
    }

    cout<<solve(N,arr)<<"\n";
    return 0;
}