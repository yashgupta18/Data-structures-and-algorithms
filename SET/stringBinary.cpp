
#include <iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
#include<string>
#include<utility>

#include<set>
using namespace std; 
bool hasAllCodes(string s, int k) {
    int count=1<<k;
    set<string> st;
    int i=0, j=i+k-1;
    int n=s.length();
    while(j<n){

	    string str2 = s.substr(i,k);
	    cout<<str2<<endl;
	    auto it = st.find(str2);
	    if (it == st.end()){
	        count--;
	    }
	    i++;
	    j++;
	}
	cout<<"count="<<count<<endl;
	if(count==0) return true;
	return false;
}


int main() 
{ 
	cout<<hasAllCodes("011010", 2);
	return 0; 
} 

