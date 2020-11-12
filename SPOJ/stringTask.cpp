#include <iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<string>
#include<cstring>

void deleteString(string &s){
	string vowels='aeiouy'
	for(i=0; i<s.size(); i++){
		if(v.find(s[i])){
			s.dele
		}
	}
}

string insertCon(string s){
	string newString = '';
	for (int i = 0; i < s.length(); i=i+2)
	{
		newString.append(s[i]);
		newString.append('.');
	}
	return newString;
}

void convertToUC(string &newString){
	transform(newString.begin(), newString.end(), newString.begin(), ::toupper); 
	return;
}

int main(){
	string s= 'hellloo';
	deleteString(s);
	string newString=insertCon(s);
	convertToUC(newString);
}