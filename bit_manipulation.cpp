#include<iostream>
#include<vector>

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
    


    // //count no fo set bits
    // int a=5; //1011
    // int count=0;
    // while(a>0){
    //     if((a & 1)>0){
    //         count++;
    //     }
    //     a=a>>1; //right shift o 1 time
    // }
    // cout<<"count="<<count<<endl;    


    // //check if no is power of 2
    // int b=8;
    // if(b<=0) cout<<"False";
    // if((b&(b-1))==0) cout<<"True";
    // else cout<<"False";


    //XOR queries of subarray
    cout<<endl;
    int arr1[]={1,3,4,8};
    int size=sizeof(arr1)/sizeof(arr1[0]);
    int L=3, R=3 ;
    int prefix[size];
    prefix[0]=arr1[0];
    for (int i = 1; i < size; ++i)
    {
        prefix[i]=arr1[i]^prefix[i-1];
    }

     int ans=prefix[R]^prefix[L-1];
     cout<<ans;
    return 0; 

    vector<vector<int> > queries{}={
                                    {0,1},
                                    {1,2},      
                                    {0,3},
                                    {3,3}
                                };
    for (int i = 0; i < queries.size(); ++i)
    {
        cout<<queries[i];
    }

}











