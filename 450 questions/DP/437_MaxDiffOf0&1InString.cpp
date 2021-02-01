#include <iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<stack>
#include<map>
using namespace std; 

#define R 6
#define C 5

int maxDiff(string S){
    // kadane's algorithm
    int val=0;
    int ans=0;
    int csum=0;
    for (int i = 0; i < S.length(); ++i)
    {
        if(S[i]=='0'){
            val=1;
        }
        else{
            val=-1;
        }

        if(csum>0){
            csum+=val;
        }
        else{
            csum=val;
        }
        if(csum>ans){
            ans=csum;
        }
    }
    // if all 1's
    if(ans==0){
        ans=-1;
    }
    return ans;
}


int main()  
{  
    string S="11000010001";
    cout<<maxDiff(S);  
}  







