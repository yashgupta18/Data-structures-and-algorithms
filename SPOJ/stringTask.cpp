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


string deleteString(string str){
	 regex r("[aeiouyAEIOUY]");  
      
    return regex_replace(str, r, ""); 
}

string insertCon(string s){
	string newString="";
	for (int i = 0; i < s.length(); ++i)
	{
		newString=newString+"."+s[i];
	}
	return newString;
}

void convertToUC(string &newString2){
	transform(newString2.begin(), newString2.end(), newString2.begin(), ::tolower); 
	return;
}

int main(){
	string s;
	cin>>s;
	string newString1=deleteString(s);
	string newString2=insertCon(newString1);
	convertToUC(newString2);
	cout<<newString2;
}