#include <iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<string>
using namespace std; 
// 
// https://leetcode.com/discuss/interview-question/731863/online-coding-test
int triplet(int arr[], int n, int N){
    sort(arr, arr+n);
    int sum=0, count=0;
    int l=n-N;

    for (int i = l; i >=0 ; i=i-N)
    {
        count++;     
        sum+=arr[i];
        if(count==N) break;
    }
    return sum;
   
}

// Driver Code
int main()
// 123456
{
    int arr[] = {1,3,5,2,4,6}; 
    int n=sizeof(arr)/sizeof(arr[0]);
    int N=n/3;
    cout<<triplet(arr, n, N);
    return 0;
}



