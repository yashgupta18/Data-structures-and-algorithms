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


void checkString(string s){
	string check="hello";
	int count=0, a=0;

	for (int i = 0; i < s.length(); ++i)
	{
		if(s[i]==check[a]){
			count++;
			a++;
		}
	}

	if(count==5){
		cout<<"YES";
		return;
	}
	else{
		cout<<"NO";
		return;
	}

}

int main(){
	string s;
	cin>>s;
	checkString(s);
}