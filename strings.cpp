#include<iostream>
#include<map>
#include<string>
#include<cstring>
#include<stack>
#include<list>
#include<unordered_map>
#include<queue>

using namespace std;
		

bool check_pallindrome(string s){
	int len=s.length();
	int start=0, end=len-1;
	while(start<end){
		if(s[start++]!=s[end--]) return false;
	}
	return true;
}

bool anagram(string a,string b){
	int l1=a.length();
	int l2=b.length();
	// cout<<l1<<" "<<l2<<" ";
	if(l1!=l2) return false;

	int count[26]={0};

	for (int i = 0; i < l1; ++i)
	{
		// cout<<a[i]-'A'<<" ";
		// cout<<b[i]-'A'<<" ";
		count[a[i]-'A']++;
		count[b[i]-'A']--;
		// count[a[i]]++;
		// count[b[i]]--;
	}

	for (int i = 0; i < 26; ++i)
	{

		if(count[i]) return false;

	}

	return true;
}


bool check_tomake_pallindrome(string a){
	int count[26]={0};
	for (int i = 0; i < a.length(); ++i)
	{
		count[a[i]-'a']++;
	}

	int odd=0;
	for (int i = 0; i < 26; ++i)
	{
		if(count[i]%2!=0)
			odd++;
		if(odd>1) return 0;
	}
	
	return 1;
}


void merge(string a, string b){
	string res="";
	for (int i = 0; i<a.length() || i<b.length(); ++i)
	{
		 if (i < a.length())  
            res += a[i];

          if (i < b.length())  
            res += b[i];     
	}

	cout<<res;
}



int main(){
	
	//Pallindrome
	// string p="ABCBA";
	// cout<<check_pallindrome(p);

	//Anagram
	// string a="SILENT";
	// string b="LISTEZ";
	// cout<< anagram(a,b);

	//ANAGRAM can be a pallindrome or not
	// string a="geeksogeeks";
	// cout<<check_tomake_pallindrome(a);

	//sort
	// string s="fmsndaab";
	// //descending
	// sort(s.begin(), s.end(), greater<char>());
	// cout<<s<<endl;
	// string n="fmsndaab";
	// //ascending
	// sort(n.begin(), n.end());
	// cout<<n;

	//merge 2 strings
	// string a="ABC";
	// string b="DEF";
	// merge(a,b);





	return 0;
}