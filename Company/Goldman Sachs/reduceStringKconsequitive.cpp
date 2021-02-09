#include <iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include <utility>

#include<stack>
#include<map>
#include<string>
using namespace std; 


void reducedString(string str, int k){
    stack<pair<char,int> > s;
    s.push(make_pair(str[0], 1));
    int n=str.length();
    int i=1;
    for (int i = 1; i < n; ++i)
    {
        //if same char increment count of top
        if(!s.empty() && s.top().first==str[i]){
            s.top().second+=1;
            // if count of top reaches k pop it.
            if(s.top().second==k){
                s.pop();
            }
        }

        else{
            s.push(make_pair(str[i], 1));
            }
    }

    string ans="";
    while(!s.empty())
        {
            for(int i = 0; i < s.top().second; i++)
            {
                ans+= s.top().first;
            }

            s.pop();
        }

    //reverse the ans
    reverse(ans.begin(), ans.end()); 
    cout<<ans;
    
}

int main()
// Q. Given a string s, a k duplicate removal consists of 
// choosing k adjacent and equal letters from s and removing them 
// causing the left and the right side of the deleted substring to concatenate together.
// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
{
    int k = 3;
    string str = "deeedbbcccbdaa";
    reducedString(str, k);
    return 0;
}



