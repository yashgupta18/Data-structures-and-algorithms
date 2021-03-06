#include<iostream>
#include<unordered_map>
using namespace std;
unordered_map<string, int> mp;

int solve(string S, int i, int j, bool isTrue){
	if(i>j) {
		return 0;
	}

	if(i==j){
		//if istrue is true 
		if(isTrue){
			// set whole side of expression as T
			return S[i]=='T';
		} 
		// if istrue is false
		else {
			// set whole side of expression as T
			return S[i]=='F';
		}
	}

	//map of format i j T/F
	string temp=to_string(i)+" "+to_string(j)+" "+to_string(isTrue);
	if(mp.find(temp)!=mp.end()){
		return mp[temp];
	}

	int ways=0;
	for (int k = i+1; k <j; k=k+2)
	{


		//solve for both T & F both sides
		int LT=solve(S, i, k-1, true);
		int LF=solve(S, i, k-1, false);
		int RT=solve(S, k+1, j, true);
		int RF=solve(S, k+1, j, false);

		//if expr is & in middle how many ways to get true
		if(S[k]=='&'){
			if(isTrue==true){
				ways=ways+ (LT*RT);
			}
			else{
				ways=ways+ (LT*RF) + (LF*RT) + (LF*RF);
			}
		}

		//if expr is & in middle how many ways to get true
		else if(S[k]=='|'){
			if(isTrue==true){
				ways=ways+ (LT*RF) + (LF*RT)+ (LT*RT);
			}
			else{
				ways= ways + (LF*RF);
			}
		}

		//if expr is & in middle how many ways to get true
		else if(S[k]=='^'){
			if(isTrue==true){
				ways=ways+(LT*RF) + (LF*RT);
			}
			else{
				ways=ways + (LT*RT) + (LF*RF);
			}
		}
	}
	//return total ways to get true
	mp[temp]=ways;
	return ways;
}

int main(){
	string S="T|T&F^T";
	int n=S.length();
	bool isTrue=true;
	// memset(t,-1, sizeof(t));
	cout<<solve(S,0,n-1, isTrue);
}




