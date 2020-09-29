#include <iostream>
#include<unordered_map>
using namespace std;


// void election(int arr[], int n, int k){ 
//     unordered_map<int ,int> difference_k; 
//     for (int i = 0; i <n ; ++i)
//     {
//     	difference_k[arr[i]];
//     }

//    unordered_map<int,int>::iterator it; 
//    int count=0;
//   		for (int i = 0; i <n ; ++i)
//   		{
//   			//search difference of arr[i] & k in map
//   			if (difference_k.find(arr[i]-k)!=difference_k.end())
//   			{
//   				count++;
//   			}
//   		}
//   		cout<<count<<endl;
// } 

int main() 
{ 
    int arr[] = {4, 2, 8, 5, 20, 1, 40, 13, 23}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    int m=*max_element(arr, arr+n);
    // findFibSubset(arr, n); 
    cout<<m;
    return 0; 
} 