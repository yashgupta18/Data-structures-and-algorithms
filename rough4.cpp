// APPLES
#include <iostream>
using namespace std;  


int solve(){
    int N, K;
    cin>>N>>K;
    cout<<N<<K;
    while(N>=0){
        if(N-K>=0){
            N=N-K;
        }
        
    }
    return N;
}      
int main()
{
    int N, K;
    cin>>N>>K;
    cout<<N<<K;
    while(N>=0){
        if(N-K>=0){
            N=N-K;
        }
        
    }
    cout<<N;
    return 0;
    
}