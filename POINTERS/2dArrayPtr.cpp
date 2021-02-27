#include <iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
#include<cmath>
#include<utility>
#include<map>
using namespace std; 

int main() 
{ 

    int a[2][3]={1,2,3,4,5,6};
    // cout<<(a[1])<<" "<<endl;
    cout<<*(*(a))<<" "<<*(*(a)+1)<<" "<<*(*(a)+2)<<endl;
    cout<<*(a[1]+0)<<" "<<*(a[1]+1)<<" "<<*(a[1]+2);
    cout<<endl;
    int arr[2][2][2] = {10, 2, 3, 4, 5, 6, 7, 8};
    cout<<*(*(*(arr)))<<endl;
    cout<<*(*(*(arr)+1))<<endl;
    cout<<*(*(*(arr))+1)<<endl;
    return 0; 
} 







