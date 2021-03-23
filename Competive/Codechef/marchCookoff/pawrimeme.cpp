#include <iostream>
#include <string>
#include <utility>

#define ll  long long int
using namespace std;

int main()
{ 
    string p="partyp";
    string q="pawri";
	ll tc;
    cin>>tc;
    while(tc--){
        string s;
        cin>>s;
        ll n=s.length();
        if(n<5){
            cout<<s<<"\n";
        }
        string newString="";
        for(int i=0;i<n;i++)
        {
            ll j=0;
            if(s[i]==p[j])
            {
                ll temp=i+1;
                while(s[i]==p[j])
                {
                    i++;
                    j++;
                }
     
                if(p[j]=='\0')
                {
                    newString=newString+q;
                    newString=newString+s[i];
                    continue;
                }
            }
            else
            {
                newString=newString+s[i];
                // i=temp;
                // temp=0;
            }
        }
        cout<<newString<<"\n";
        
    }
    return 0;
}