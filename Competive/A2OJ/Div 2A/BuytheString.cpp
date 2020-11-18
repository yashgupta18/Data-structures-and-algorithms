#include <iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<stack>
#include <numeric>      
#include<map>
#include<string>
#include<cstring>
#include<regex>

using namespace std;

int buy(int n, int c0, int c1, int h, string s){
	if(s.length()!=n) return 0;
	if(c0==c1) return n;
	int n0=0, n1=0;
	for (int i=0;i<s.length();i++) 
  	{
        // checking character in string 
        if (s[i] == '0'){
        	n0++;
        } 
        else{
        	n1++;
        }
	}

	long long int sum;
	int count=0;

	if(c0<c1){
		sum=n0*c0;
		if((c0+h) < c1){
			sum+=(n1*(c0+h));
		}
		else{
			sum+=n1*c1;
		}
	}
	else{
		sum=n1*c1;
		if((c1+h) < c0){
			sum+=(n0*(c1+h));
		}
		else{
			sum+=n0*c0;
		}
	}
	
	return sum;
}


int main(){
	long long int t;
	vector< long long int> v;
	cin>>t;
	while(t){
		long long int n,c0,c1, h;
		string s;
		cin>>n>>c0>>c1>>h;
		cin>>s;
		v.push_back(buy(n,c0,c1,h,s));
		t--;
	}

	for (int i = 0; i < v.size(); ++i)
	{
		cout<<v[i]<<endl;
	}

	return 0;
}