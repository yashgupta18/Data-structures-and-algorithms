#include <iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
#include<cmath>
#include<utility>

#include<map>
#define MUL(a,b) a*b
using namespace std; 

bool checkPowersOfThree(int n) {
        int left=n;
        int ans;
        int i=1;
        map<int, int> mp;
        while(left>0){
        	
            for(int i=left; i>=0; i--){
                if(pow(3, i)<=left && mp.find(i)==mp.end()){
                	mp[i]=+1;
                    ans=pow(3,i);
                    left=left-ans;
                    cout<<"left="<<left<<endl;
                    cout<<"ans="<<ans<<endl;
                    break;
                }
            }

            
            
            if(left==0){
            	cout<<"true";
                return true;
            }
        }
        cout<<"false";
        return false;
    }
int main() 
{ 
   	bool ans=checkPowersOfThree(11);
    return 0; 
} 







