#include <iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<string>
using namespace std; 


//make 2 arr to store max of left and right of current index

void sumFind(int arr[], int n, int sum){
    unordered_map<int, int> mp;

    for (int i = 0; i < n; ++i)
    {
        int curr=sum-arr[i];
        
        if(mp.find(curr)!=mp.end()){
            cout<<"PAIR="<<arr[i]<<" "<<curr<<endl;
        }else{
            mp[arr[i]]++;
        }
    }
    return;
}

// Driver Code
int main()
{
   int arr[] = {0, -1, 2, -3, 1};
   int n=sizeof(arr)/sizeof(arr[0]);
   int sum=-2;
   sumFind(arr, n, sum);
    return 0;
}



