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
        // cout<<res<<endl; 
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


    // //check if no. is power of 2
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
     // cout<<ans;
    

    
    //XOR all pair sums

    int arr3[]={ 1, 5, 6 };
    int arr3_size=sizeof(arr3)/sizeof(arr3[0]);
    int sum=0;
    for (int i = 0; i < arr3_size; ++i)
    {
        sum=sum ^ arr3[i];
    }
    // cout<<endl<<sum* 2;


    //AND product of a range of number
    // https://www.youtube.com/watch?v=shKgCtEAVWQ&list=PL2q4fbVm1Ik7ip1VkWwe5U_CEb93vw6Iu&index=14
    long long int low=12, upper=15; //find AND product of numbers btw 12 and 15 
    // long long int a,b;
    long long int d=upper-low, rresult=0, ff=1;
    for (int i = 0; i < 32; ++i)
    {
        //use pattern of bit table 8 0's, 8 1's,  4 0's, 4 1's....
        if(d>(ff<<i)) continue;
        else{
            //check if ith bit is set or not for lower and upper
            if((low & (ff<<i)) && (upper & (ff<i))){
                rresult+=ff<<i;
            }
        }
    }
    // cout<<endl<<"AND Product=  "<<rresult<<endl;


    //AND of subarray of an array
    //To do-find subarray, AND operation of suarray, AMD of result obtained 
    //Algo- if size of array is even res=0, else xor elements at even places 
    int arr5[]={ 3,4,1,5};
    long long int arr5_size=sizeof(arr5)/sizeof(arr5[0]);
    long long int count5=0;
    long long int res5=0;
    
    if(arr5_size%2==0){
        cout<<"Res="<<0;
    }else{
        //XOR even places elements 
        for (int i = 0; i < arr5_size; i+=2)
        {
            res5^=arr5[i];
        }
        cout<<endl<<res5<<endl;
    }



    //find number which occors only one time
    int arr6[]={2,2,2,3,6,6,6};
    //score stores sum of bit positions. in end if bit position is not divisible by 3 it means that bit is needed for odd one out
    vector<int> store(32,0);

    // for each element in arr check its bits
    for (int i :arr6)
    {   
        // if jth bit is set increase score[j] by 1
        for (int j = 0; j < 32; ++j)
        {
            if(i & (1<<j)){
                store[j]++;
            }
        }
    }

    int res6=0;
    //for each in store
    for (int i = 0; i < 32; ++i)
    {
        // if it is not divisible by 3 we need that bit position set so 2 raise to power ith pos.
        if(store[i]%3==1){
            res6+=(1<<i);
        }
    }
    cout<<endl<<"RESULT6="<<res6<<endl;
    





    // Total Sum of all Pair XOR
    int arr4[]={ 5, 9, 7, 6 };
    int arr4_size=sizeof(arr4)/sizeof(arr4[0]);
    int zero_cnt=0, one_cnt=0; 
    long long int nsum=0;
    for (int i = 0; i < 31; ++i)
    {
        // long long int p2=0;
        int zero_cnt=0, one_cnt=0;
        for (int j = 0; j < arr4_size; ++j)
        {
            //ith it is set or not
            if(arr4[j] & 1<<i){
                //if set
                one_cnt++;
                
            }else{
                //if not set
                zero_cnt++;
            }
        }
        int p2=zero_cnt * one_cnt ;

        //2 raise to power p2
        nsum+= (1<<i)*p2;
    }
    // cout<<endl<<nsum<<endl;




    return 0; 
}











