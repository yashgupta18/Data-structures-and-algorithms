// A Dynamic Programming based C++  
// implementation to count decodings 
#include <iostream> 
#include <cstring> 
using namespace std; 
  
int gethero(){
    int n, arr[n];
    cin>>n;
    // n=read(int);
    for (int i = 0; i < n; ++i)
    {
        /* code */
        cin>>arr[i];
    }

    if(n==2 && arr[0]==arr[1]) return 0;
    sort(arr, arr+n);
    for (int i = 0; i < n; ++i)
    {
        /* code */
        cout<<arr[i]<<" ";
    }
    
    for (int i = 1; i < n; ++i)
    {
        /* code */
        if(arr[i]>arr[i-1]){
            return n-i;
        }
    }

    return 0;
}
  
// Driver program to test above function 
int main() 
{ 
    int tc;
    cin>>tc;
    // tc = read(int);

    while(tc--){
        cout<<gethero()<<endl;
    }

    return 0;
} 