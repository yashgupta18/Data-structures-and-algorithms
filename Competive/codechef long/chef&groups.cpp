#include <iostream>
#include <string>

#define ll long long int
using namespace std;
// Q. https://www.codechef.com/problems/PALPALS
int main() {
	// your code goes here
	ll tc;
	cin>>tc;
	while(tc){
	    string s;
	    cin>>s;
	    int grp=0;

	    for (int i = 0; i < s.length(); ++i)
	    {
	    	if(s[i]=='1'){
	    		while(i<s.length()){
	    			if(s[i]=='1'){
	    				i++;
	    			}
	    			else{
	    				break;
	    			}
	    		}
	    		grp++;
	    	}
	    }
	    cout<<grp<<"\n";
	    tc--;
	}
	return 0;
}

