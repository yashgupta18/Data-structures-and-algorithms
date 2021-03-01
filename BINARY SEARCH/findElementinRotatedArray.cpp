#include<iostream>
#include<vector>
#include<queue>

using namespace std;


int bst(int arr[], int N ){
    int left=0, right=N-1;
    while(left<=right){
        int mid = left + (right - left) / 2;
        int ans=arr[mid];
        int prev=arr[(mid+N-1)%N];
        int next=arr[(mid+1)%N];
        if(ans<prev && ans<next) return mid;
        if(ans>=arr[left]) {
            left=mid+1;
        }
        else if(ans<=arr[right]){
            right=mid-1;
        }
    }
    return -1;
}

int binaryS(int left, int right, int arr[], int target){
    if(left>right) return -1;
    while(left<=right){
        int mid = left + (right - left) / 2;
        int ans=arr[mid];
        if(ans==target) return mid;
        if(ans>left) {
            left=mid+1;
        };
        if(ans<right) {
            right=mid-1;
        };
        
    }
    return -1;
    
}

int search(int arr[], int n, int target) {
    int pivot= bst(arr, n); 
    if (arr[pivot] == target) 
        return pivot; 
  
    if (arr[0] <= target) 
        return binaryS( 0, pivot - 1, arr,target); 
  
    return binaryS( pivot + 1, n - 1, arr, target);

}


int main(){
    int arr[]={4,5,6,7,0,1,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    int target=2;
    cout<<search(arr, n, target);
    return 0;
}















