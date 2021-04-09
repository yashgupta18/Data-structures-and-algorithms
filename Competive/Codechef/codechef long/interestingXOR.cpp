#include <iostream>
#include <cmath>
#include <utility>

#define ll  long long int
using namespace std;

int main()
{ 
// Watch this
    // https://www.youtube.com/watch?v=A4VgJ6Yz1fc&ab_channel=LearnCompetitiveProgrammingwithCodeChef
	ll tc;
    cin>>tc;
    while(tc--){
        ll c;
        cin>>c;
        ll id=0;
        ll flag=1;
        ll a=0,b=0;

        // find Most significant bit in c
        for(int i=31; i>=0; --i){
            // if current bit is 1 (i.e MSB)- store it's index and break
            if((1<<i)&c){
                id=i;
                break;
            }
        }

        // set bits
        // Set MSB of
        for (int i = id; i >=0 ; --i)
        {
            if((1<<i)&c)
            {
                if(flag){
                    a=a|(1<<i);
                    flag=0;
                }else{
                    b=b|(1<<i);
                }
            }
            else{
                a=a| (1<<i);
                b=b|(1<<i);
            }
        }
        
        cout<<a*b<<"\n";
    }
    return 0;
}