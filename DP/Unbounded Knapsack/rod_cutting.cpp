#include<iostream>
using namespace std;


int max(int a, int b) 
{ 
    return (a > b) ? a : b; 
} 

void rod_cutting(int price[], int length[], int rod_length, int n){
	int t[n+1][rod_length+1];

	// Build table t[][] in bottom up manner 
    for (int i = 0; i <n+1; i++) { 
        for (int j = 0; j <rod_length+1; j++) { 
        	// initialize 1st row and column with 0 rest with -1
            if (i == 0 || j == 0){
            	t[i][j] = 0; 
            }else{
            	t[i][j] = -1; 
            } 
        } 
    } 

	cout<<"Before DP"<<endl;
	for (int i = 0; i < n+1; ++i)
	{
		for (int j = 0; j < rod_length+1; ++j)
		{
			cout<<t[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;

	for (int i = 1; i < n+1; ++i)
	{
		for (int j = 1; j < rod_length+1; ++j)
		{
			if(length[i-1]<=j){
				t[i][j]=max(price[i-1]+ t[i][j-length[i-1]] , t[i-1][j]);
			}
			else{
				t[i][j]=t[i-1][j];
			}
		}
	}

	cout<<"After DP"<<endl;
	for (int i = 0; i <n+1; ++i)
	{
		for (int j = 0; j < rod_length+1; ++j)
		{
			cout<<t[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;

	cout<<t[n][rod_length];
	return;
}



int main(){
	int price[]={1,5,8,9,10,17,17,20};
	int length[]={1,2,3,4,5,6,7,8};
	int n=sizeof(length)/sizeof(length[0]);
	int rod_length=8;

	rod_cutting(price, length, rod_length, n);
}