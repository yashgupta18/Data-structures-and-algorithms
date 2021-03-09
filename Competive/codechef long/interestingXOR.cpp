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
        ll C;
        cin>>C;
        ll dpow=1;
        ll i=0;
        while(true){
        	dpow=pow(2,i);
        	if(dpow>C) break;
        	else i++;
        	
        }
        ll p = (ll)(log2(C));
        ll A, B;
        ll mask = 1 << p; 
    	A= (A & ~mask) | ((1 << p) & mask); 
    	B=(A & ~mask) | ((0 << p) & mask); 
    }
    return 0;
}