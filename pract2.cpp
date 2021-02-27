// C++ program to caulate height of Binary Tree 
// from InOrder and LevelOrder Traversals 
#include <iostream> 
#include <vector> 

using namespace std;

int solve(){
    int N, K;
    cin>>N>>K;
    while(N>=0){
        if(N-K>=0){
            N=N-K;
        }else{
            break;
        }
        
    }
    // cout<<N;
    return N;
}      
int main()
{
    int tc;
    cin>>tc;
    vector<int> ans;
    while(tc--){
        cout<<endl<<solve();
    }
    // for (int i = 0; i < ans.size(); ++i)
    // {
    //     /* code */
    //     cout<<ans[i]<<endl;
    // }
    
    return 0;
    
}
 