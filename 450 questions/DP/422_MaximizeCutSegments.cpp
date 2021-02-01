#include <iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<stack>
#include<map>
using namespace std; 

int dp[10005];
int maxCutSeg(int l, int p, int q, int r){
    if(l==0) return 0;
    if(dp[l]!=-1) return dp[l];
    int ans1=INT_MIN, ans2=INT_MIN, ans3=INT_MIN;
    if(l>=p) ans1=maxCutSeg(l-p, p, q, r);
    if(l>=q) ans2=maxCutSeg(l-q, p, q, r);
    if(l>=r) ans3=maxCutSeg(l-r, p, q, r);
	return dp[l]=1+max(ans1, max(ans2, ans3));
}


int main(){
    memset(dp, -1, sizeof(dp));
    int l=11, p=2, q=3,r=5;
	cout<<maxCutSeg(l,p,q,r);
	return 0;
}







