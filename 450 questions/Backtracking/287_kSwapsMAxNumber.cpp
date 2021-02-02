#include<iostream>
#include<string>

using namespace std;
#define N 4 


string swap(string s1, int i, int j){
	char si=s1[i];
	char sj=s1[j];
	
	string start=s1.substr(0, i);
	string mid=s1.substr(i+1, j-1);
	string end=s1.substr(j+1, s1.length());
	// cout<<"swapped="<<start+sj+mid+si+end<<endl;
	string newStr=start+" "+si+" "+mid+" "+sj+" "+end;
	return newStr;
}

void solve(string str, int k, string &max){
	// cout<<max<<endl;
	int result=str.compare(max);
	// cout<<result<<endl;
	if(result>0){
		max=str;
	}

	if(k==0){
		return;
	}

	for (int i = 0; i < str.length()-1; ++i)
	{
		for (int j = 1; j < str.length(); ++j)
		{
			if(str[j]>str[i]){
				str=swap(str, i, j);
				solve(str, k-1, max);
				str=swap(str, i, j);
			}
			
		}
	}
}



int main(){
	string str="123456";
	int k=4;
	string max=str;
	// solve(str, k, max);
	str=swap(str, 3, 5);
	cout<<str<<endl;
	cout<<max;
	return 0;
}