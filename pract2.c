#include<iostream>
#include<map>
#include<list>
#include<unordered_map>
#include<map>
#include<set>
#include<queue>
// #define V 5
using namespace std;

int maxSum(int arr[], int n){
	int i, j, temp;
	
	

	for(i=0; i<n-1; i++)
	{	
		for(j=i+1; j<n; j++)
		{
			if(arr[i] < arr[j])
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		cout<<arr[i]<<" ";
	}
	
// Now return sum of first 4 in the Array

	int sum=0;

	for(i=0; i<4; i++)
	{ 
		// cout<<a[i]<<endl;÷
		sum+=arr[i];
	}
	return sum;
}

int main(){
	int arr[]={0,0,2,3,7,1};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<maxSum(arr,n);
}

// int Coindeterminer(int coinsArr[],int num) 
// { 
// 	 int n=sizeof(coinsArr)/sizeof(coinsArr[0]); 
// 	 if(num<5) return num; 
// 	 int count=num/11; 
// 	if((num%11)%2==0){ 
// 	 	return count+2; 
// 	}
// 	else{
// 	 	return count+1; 	 	}
// 	}

// int main(){
// 	int coinsArr[]={1,5,7,9,11};
// 	int num=22;
// 	cout<<Coindeterminer(coinsArr, num);
// }