#include <iostream>
#include <queue>

using namespace std; 
  
// Return sum of maximum sum alternating 
// sequence starting with arr[0] and is first 
// decreasing. 
void k_largest(int arr[], int n, int k){
  priority_queue<int,vector<int>,greater<int> > min_heap;
  for (int i = 0; i <n-2; ++i)
  {
    //use max heap or min heap
    min_heap.push(abs(arr[i]-arr[i+2]));
  }
  
  cout<<min_heap.top();
  return;
}
  
//Driver program 
int main() 
{ 
    int arr[]= {1, 12, 7, 9 ,5 ,17}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    int k=3;
    k_largest(arr , n, k ); 
    return 0; 
}