#include <iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<stack>
#include<map>
using namespace std; 
// #def

// bool isInside(int x, int y, int N) 
// { 
//     if (x >= 1 && x <= N && y >= 1 && y <= N) 
//         return true; 
//     return false; 
// } 
  

int count(int arr[], int m, int n){
	int i, j; 
    int t[n + 1][m + 1]; 
  
    // Build table t[][] in bottom up manner 
    for (i = 0; i <=m; i++) { 
        t[0][j]=0;
    }
    for (i = 0; i <=n; i++) { 
        t[i][0]=1;
    }

     for (int i = 1; i <= n; ++i)
     {
        /* code */
        for (int j = 1; j <=m; ++j)
        {
           t[i][j]=-1;
        }
     }

    for (int i = 1; i <= n; ++i)
     {
     	/* code */
     	for (int j = 1; j <=m; ++j)
     	{
     		/* code */
     		if(arr[i-1]<=j){
     			t[i][j]=(t[i][j-arr[i-1]] + t[i-1][j]);
     		}
     		else{
     			t[i][j]=t[i-1][j];
     		}
     	}
     }

     cout<<"After DP"<<endl;
    for (i = 0; i <= n; i++) { 
        for (j = 0; j <= m; j++) { 
            cout<<t[i][j]<<" ";
        } 
        cout<<endl;
    } 
    cout<<endl; 

     return t[n][m]; 
	
}


int main() 
{ 
    int arr[] = { 1,5,7,9,11 };
    int n = sizeof(arr)/sizeof(arr[0]); 
    int m = 16; 
    cout << count(arr, m, n); 
    return 0; 
} 






