#include <iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std; 


// Formula
// i==   0  1  2  3
// arr=  8  3  1  2  sum= 8*0 + 3*1 + 1*2 + 2*3 --- S'
// after 1 rotation  
// arr=  3  1  2  8  sum= 3*0 + 1*1 + 2*2 + 8*3 --- S

// S=S' + X +arr[i-1] * (n-1)
// X= 8+3+1+2 - 8
// X= CummSum - 8
// X= CummSum - arr[i-1]

// Therefore
// S=S' + CummSum+ arr[i-1] * n
 
int rotateSum(int arr[], int n){
	int arrSum=0;
	for (int i = 0; i < n; ++i)
	{
		arrSum+=arr[i];
	}

	int ans=0;
	for (int i = 0; i < n; ++i)
	{
		ans+=arr[i]*i;
	}

	int finalSum=ans;
	for (int i = 1; i < n; ++i)
	{
		int currVal=ans-arrSum+arr[i-1]*n;
		ans=currVal;
		finalSum=max(finalSum, currVal);
	}

	return finalSum;
}	


int main(){
	int arr[] = {8, 3, 1, 2};
	int n=sizeof(arr)/sizeof(arr[0]);
	int ans=rotateSum(arr, n);
	cout<<ans;
	return 0;
}