#include <iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<string>
using namespace std; 


//make 2 arr to store max of left and right of current index

int waterTrapping(int arr[], int n){
    int maxL[n], maxR[n];
    maxL[0]=arr[0];
    maxR[n-1]=arr[n-1];
    for (int i = 1; i < n; ++i)
    {
        maxL[i]=max(maxL[i-1],arr[i]);
    }

    for (int i = n-2; i >=0; --i)
    {
        maxR[i]=max(maxR[i+1],arr[i]);
    }

    int ans=0, water;
    for (int i = 0; i < n; ++i)
    {
        water=min(maxL[i], maxR[i]);
        int temp=water-arr[i];

        ans+=temp;
    }

    return ans;
}

// Driver Code
int main()
{
   int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
   int n=sizeof(arr)/sizeof(arr[0]);
   int ans= waterTrapping(arr, n);
   cout<<ans;
    return 0;
}



