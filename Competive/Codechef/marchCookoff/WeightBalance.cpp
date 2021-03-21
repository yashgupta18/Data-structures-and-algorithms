#include <iostream>
#include <cmath>
#include <utility>

#define ll  long long int
using namespace std;

int main()
{ 
	ll tc;
    cin>>tc;
    while(tc--){
        ll w1,w2,x1,x2,m;
        cin>>w1>>w2>>x1>>x2>>m;
        ll gain=w2-w1;
        // ll pm=x2-x1;
        ll allowed1=m*x1;
        ll allowed2=m*x2;
        if(gain>=allowed1 && gain<=allowed2){
            cout<<1<<"\n";
        }else{
            cout<<0<<"\n";
        }
        
    }
    return 0;
}