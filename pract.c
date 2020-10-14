#include<iostream>
#include<vector>
using namespace std;

void equation(int arr1[], int n){
	vector<int> v;
	int j=0;
	for (int i = s; i < n; ++i)
	{
		int temp=arr1[i+1]*(2^(j-1));
		j++;
		v.push_back(temp);

	}

	for (int i = 0; i < v.size(); ++i)
	{
		cout<<v[i]<<" ";
	}
	return;
}


int main(){
	int arr1[]={3,2};
	int n=sizeof(arr1)/sizeof(arr1[0]);
	equation(arr1, n);

	return 0;
}