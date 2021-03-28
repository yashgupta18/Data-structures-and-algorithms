#include <iostream>
#include <cmath>
#include <utility>

#define ll  long long int
using namespace std;

int main()
{ 
	
        ll r,o,c;
        cin>>r>>o>>c;
        
        int rem=20-o;
        int maxRuns=(rem*6)*6;
        if(c+maxRuns>r){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }    
    return 0;
}