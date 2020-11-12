#include<iostream>
#include<map>
#include<string>
#include<cstring>
#include<stack>
#include<list>
#include<unordered_map>
#include<queue>

using namespace std;
	
string hi="Hello";
string first="The coding";
string last="Library";

   // https://www.geeksforgeeks.org/stdstring-class-in-c/
int main(){
	// cout<<"Input:";
	// string s;
	// getline(cin, s);
	// cout<<s<<endl;

	// for (int i = 0; i < s.size(); ++i)
	// {
	// 	cout<<s[i]<<" ";
	// }
	// cout<<endl;

	// for(auto i: s){
	// 	cout<<i<<" ";
	// }
	// cout<<endl;

	// cout<< hi<<endl;	

	// string combo=first+ last;
	// cout<<combo<<endl;

	// int length_combo=combo.length();
	// cout<<length_combo<<endl;

	// char first_letter=combo[0];
	// cout<<first_letter<<endl;

	// //change 1st to 'z'
	// combo[0]='z';
	// cout<<combo[0]<<endl;

	// char ch='g';
	// // strncat(hi, &ch, 1);
	// // cout<<hi<<endl;

	// string test="me";
	// test.append("gooo");
	// cout<<test;

	// combo.clear();
	// cout<<"Combo:"<<combo<<endl;

	// //space is also counted. Starts from 0.Case sensitive
	// combo="Huluguluz counter strike";
	// int pos_combo=combo.find("z");
	// cout<<pos_combo<<endl;

	// //print from find till last
	// string stringAfterPos=combo.substr(pos_combo);
	// cout<<stringAfterPos<<endl;

	// //check 
	// string p="mamamia";
	// if(s.compare("mamamia")){
	// 	cout<<"its a match"<<endl;
	// }else{
	// 	cout<<"No match"<<endl;
	// }

	// p.insert(2,"X");
	// cout<<p<<endl;



	string s23 = "hellloo";
	string newString="";
	string dot = ".";
	for (int i = 0; i < s23.length(); ++i)
	{
		newString=newString+s23[i]+".";
	}
	cout<<newString;

	return 0;
}