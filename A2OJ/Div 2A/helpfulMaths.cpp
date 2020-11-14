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


void helpfulMaths(string s){
	int count1=0, count2=0,count3=0;
	for (int i = 0; i < s.length(); i++)
	{
		if(s[i]=='1') 
			count1++;
		else if(s[i]=='2')
			count2++;
		else if(s[i]=='3')
			count3++;
	}

	// cout<<count1;
	string newstring="";
	for (int i = 0; i < count1; ++i)
	{
		newstring=newstring+'1'+'+';
	}

	for (int i = 0; i < count2; ++i)
	{
		newstring=newstring+'2'+'+';
	}

	for (int i = 0; i < count3; ++i)
	{
		newstring=newstring+'3'+'+';
	}
	newstring.pop_back();
	cout<<newstring;
	return;
}


int main(){
	string s;
	cin>>s;
	helpfulMaths(s);
	return 0;
}