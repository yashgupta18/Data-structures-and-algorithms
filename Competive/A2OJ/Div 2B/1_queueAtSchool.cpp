#include <iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<string>
#include<cstring>
#include<regex>

using namespace std;

string queueSchool(int n, int t, string s){
	while(t>0){
		// cout<<1<<endl;
		for (int i = n-1; i >=0; --i)
		{
			// cout<<"hello"<<endl;
			/* code */
			if(s[i]=='G' && s[i-1]=='B'){
				swap(s[i], s[i-1]);
				i--;
			}
		}
		t--;
	}
	// cout<<s;
	return s;
}

int main(){
	int n, t;
	cin>>n>>t;
	string s;
	cin>>s;
	// cout<<s<<endl;
	cout<<queueSchool(n,t,s);
	// cout<<newString2;
}