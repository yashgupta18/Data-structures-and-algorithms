#include <iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std; 
 
void farthest_min(int arr[], int n){
	int subArr[n];
	subArr[n-1]=arr[n-1];
	for (int i = n-2; i >=0; --i)
	{
		subArr[i]=min(subArr[i+1], arr[i]);
	}

	for (int i = 0; i < n; ++i)
	{	
		int ans=-1;
		int low=i+1, high=n-1;
		while(low<=high){
			int mid=(low+high)/2;
			if(subArr[mid]<arr[i]){
				ans=mid;
				low=mid+1;
			}
			else{
				high=mid-1;
			}
		}
		cout<<ans<<" ";
	}

}	

int main()
{
    int a[] = { 3, 1, 5, 2, 4 };
    int n = sizeof(a) / sizeof(a[0]);
 
    farthest_min(a, n);
 
    return 0;
}