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

	long long int sum=n0*c0 + n1*c1;
	int count=0;
	for (int i = 0; i < s.length(); ++i)
	{
		if(s[i]=='0'){
			long long int tempSum=0;
			s[i]='1';
			n1++;
			n0--;
			count++;
			tempSum=n0*c0 + n1*c1 + count*h;
			if(tempSum>sum){
				n1--;
				n0++;
				s[i]='0';
				break;
			}
			else{
				sum=tempSum;
			}
		}
		
	}
	count=0;

	for (int i = 0; i < s.length(); ++i)
	{
		if(s[i]=='1'){
			int tempSum=0;
			s[i]='0';
			n0++;
			n1--;
			count++;
			tempSum=n0*c0 + n1*c1 + count*h;
			if(tempSum>sum){
				n0--;
				n1++;
				s[i]='1';
				break;
			}
			else{
				sum=tempSum;
				
			}
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