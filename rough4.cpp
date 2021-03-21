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

int solve(string s, string t) {
    map<char, int> mp;
    for(int i=0;i<s.length(); i++){
        mp[s[i]]++;
    }

    for(int i=0;i<t.length();i++){
        if(mp.find(t[i])==mp.end()){
            return -1;
        }
    }

    int i=0,j=0;
    while(s[i]!=t[j]){
        i++;
        cout<<i<<endl;
    }
    int count=1;
    while(j<t.length()){
        cout<<i<<" "<<j<<endl;
        if(s[i]==t[j]){
            i++;
            j++;
            if(i>=s.length()){
                i=0;
                count++;
            }
        }
        else{
            i++;
        }
    }
    return count;
}

int main(){
	
    cout<<solve("dab", "abbd");
    return 0;



}












