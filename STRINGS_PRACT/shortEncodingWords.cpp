#include<iostream>
#include<map>
#include<string>
#include<cstring>
#include<stack>
#include<list>
#include<unordered_set>
#include<queue>

using namespace std;
		


int main(){
	vector<string> words;
	words.push_back("time");
	words.push_back("me");
	words.push_back("line");
        unordered_set<string> s(words.begin(), words.end());
        for (auto elem : s)
		{
		    cout << elem << " , ";
		}
        // for (string w : s){
        //     for (int i = 1; i < w.size(); ++i){
        //     	s.erase(w.substr(i));
        //     }
   
        // }

        // int res = 0;
        // for (string w : s) {
        // 	res += w.size() + 1;
        // }
        // cout<<res;



	return 0;
}