#include <iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<string>
using namespace std; 


 
void checkanagram(string str1, string str2){
	int count=0;
    for (int i = 0; i < str1.length(); ++i)
    {
        count+=str1[i];
        // count-=str2[i];
    }

    for (int i = 0; i < str2.length(); ++i)
    {
        // count+=str1[i];
        count-=str2[i];
    }
    if(count==0){
        cout<<"Anagram";
        return;
    }
    else{
        cout<<"Not anagram";
        return;
    }


}	


int main(){
	string a="SILENT";
    string b="LISTEN";
    checkanagram(a,b);
	// cout<<ans;
	return 0;
}