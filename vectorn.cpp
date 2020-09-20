// Modifiers in vector 
#include <bits/stdc++.h> 
#include <vector> 
#include <iostream>

using namespace std; 
   
int sortandmerge(int arr[],int s1){
    int sum=0, max=arr[0];
    for (int i = 0; i < s1; ++i)
    {
        sum=sum+arr[i];
        if (max<sum)
        {
             max=sum;
             // cout<<max;
        }
        if(sum<0){
            sum=0; 
        }        

        
    }

    return max;
}

int main() 
{ 
    // Assign vector 
   int arr1[]={-2, -3, 4, -1, -2, 1, 5, -3};
   // int arr2[3]={1,4,5};
   int l1=sizeof(arr1)/sizeof(arr1[0]);
   // int l2=sizeof(arr2)/sizeof(arr2[0]);
   // cout<<l1<<l2;
   cout<<sortandmerge(arr1,l1);
}