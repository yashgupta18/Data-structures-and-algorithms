#include<iostream>
using namespace std;  
// Function to return the only odd 
// occurring element 
int findOdd(int arr[], int n) 
{ 
    int res = 0, i; 
    for (i = 0; i < n; i++){ 
        res ^= arr[i];
        cout<<res<<endl; 
    }
    return res; 
} 
  
// Driver Method 
int main(void) 
{ 
    int arr[] = { 12, 12, 14,1, 14, 14, 14 }; 
    // int n = sizeof(arr) / sizeof(arr[0]); 
    //     // cout<<"The odd occurring element is "<<findOdd(arr, n); 

    // int mask=0;
    // int city=2;
    // cout<<city<<endl;
    // cout<<(1<<city);
    

    //check if ith bit is set or not
    int p=12;
    int f=1;
    f=(f<<2 );
    int res=(p & f);
    if(res==0){
        cout<<"False";
    }
    else{
        cout<<"true";
    }
    


    //count no fo set bits
    int n=5; //1011
    int count=0;
    while(n>0){
        if((n & 1)>0){
            count++;
        }
        n=n>>1; //right shift o 1 time
    }
    cout<<"count="<<count<<endl;    

    



    return 0; 
}











