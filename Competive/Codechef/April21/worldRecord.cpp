#include<iostream>
#include <vector>
#include <iomanip>      // std::setprecision

#define ll  long long int
using namespace std;

float roundoff(float time){
	float value=(int)(time*100 + 0.5);
	return (float)value/100;
}
// https://www.codechef.com/APRIL21C/problems/BOLT
int main()
{
	float tc;
	cin>>tc;
	while(tc--){
		float k1,k2,k3,v, record=9.58;
	    cin>>k1>>k2>>k3>>v;
	    float temp=k1*k2*k3*v;
	    float ans=100/temp;
	    ans=roundoff(ans);
	    // ans=setprecision(3);
	    if(ans<record){
	    	cout<<"YES"<<endl;
	    }else{
	    	cout<<"NO"<<endl;
	    }
	}
    
    
    
    return 0;
}






