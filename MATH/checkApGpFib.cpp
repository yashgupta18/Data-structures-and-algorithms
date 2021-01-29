#include<iostream>
#include<stack>
#include <string.h>
#include<vector>
#include <cmath>

using namespace std;

bool checkIsAP(int arr[], int n) 
{ 
    if (n == 1) 
        return true; 
  
    // Sort array 
    sort(arr, arr + n); 
  
    // After sorting, difference between 
    // consecutive elements must be same. 
    int d = arr[1] - arr[0]; 
    for (int i = 2; i < n; i++) 
        if (arr[i] - arr[i - 1] != d) 
            return false; 
  
    return true; 
} 
int Nth_of_AP(int a, int d, int N) 
{  
    // using formula to find the  
    // Nth term t(n) = a(1) + (n-1)*d 
    return (a + (N - 1) * d); 
      
} 


bool checkIsFibonacci(int arr[], int n) 
{ 
    if (n == 1 || n == 2) 
        return true; 
  
    // Sort array 
    sort(arr, arr + n); 
  
    // After sorting, check if every 
    // element is equal to the 
    // sum of previous 2 elements 
  
    for (int i = 2; i < n; i++){
        if ((arr[i - 1] + arr[i - 2])!= arr[i]){ 
            return 0;
          } 
    }
    return 1; 
} 
int nextFibonacci(int n, int m) 
{ 
    return n+m;
}

bool is_geometric(int arr[], int n) 
{ 
    if (n == 1) 
        return true; 
  
    // Calculate ratio 
    int ratio = arr[1] / (arr[0]); 
  
    // Check the ratio of the remaining 
    for (int i = 1; i < n; i++) { 
        if ((arr[i] / (arr[i - 1])) != ratio) { 
            return false; 
        } 
    } 
    return true; 
} 
int Nth_of_GP(int a, int r, int n) {
   // the Nth term will be
   return( a * (int)(pow(r, n - 1)) );
}
int chris(int arr[], int n){
  if(n==0) return 1;

   
   if(checkIsFibonacci(arr, n)==1){
    cout<<"fb";
    return nextFibonacci(arr[n-1], arr[n-2]);
   }
   else if(checkIsAP(arr, n)==1){
    cout<<"Ap";
    return Nth_of_AP(arr[0], arr[1]-arr[0], n+1);
   }
   else if(is_geometric(arr, n)==1){
    cout<<"gp";
    return Nth_of_GP(arr[0], round(arr[1]/arr[0]), n+1);
   }
   else{
    return -999;
   }
}

int main() {
   int arr[]={1,2,3,4};
   int n=sizeof(arr)/sizeof(arr[0]);
   cout<<chris(arr, n);
    return 0;
}



