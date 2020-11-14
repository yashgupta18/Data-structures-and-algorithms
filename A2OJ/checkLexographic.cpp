#include <iostream>
#include<stdio.h>
#include<string.h>
#include<unordered_map>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<string>
#include<cstring>
#include<regex>
using namespace std;

void checkLexicographic(string s1, string s2){
	for (int i = 0; i < s1.length(); ++i)
	{
		if(s1[i]>='A' && s1[i]<='Z'){
			s1[i]+=32;
		}
		if(s2[i]>='A' && s2[i]<='Z'){
			s2[i]+=32;
		}

		if(s1[i] > s2[i]){
			cout<<"1";
			return;
		}

		if(s2[i]>s1[i]){
			cout<<"-1";
			return;
		}
	}

	cout<<'0';
	return;
}

int main(){
	string s1,s2;
	cin>>s1;
	cin>>s2;
	checkLexicographic(s1, s2);
	return 0;
}