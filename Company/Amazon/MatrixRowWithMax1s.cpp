#include <iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<string>
using namespace std; 
#define R 4  
#define C 4 

// https://www.geeksforgeeks.org/find-the-row-with-maximum-number-1s/
// Find the row with maximum number of 1s

// Following method works in O(m+n) time complexity in worst case.


int rowWithMax1s(bool mat[R][C]){
    int j=C-1;
    int max_row=0;
    for (int i = 0; i <C-1; ++i)
    {
        if(mat[0][i]==1) {
            j=i;
            break;
        }
    }
    for (int i = 0; i < R-1; ++i)
    {
        while(j>=0 && mat[i][j]==1){
            max_row=i;
            j--;
        }
    }
    return max_row;
}

// Driver Code
int main()  
{  
    bool mat[R][C] = { 
                    {0, 0, 0, 0},  
                    {0, 0, 1, 1},  
                    {0, 1, 1, 1},  
                    {0, 0, 0, 0}
                };  
  
    cout << "Index of row with maximum 1s is " << rowWithMax1s(mat);  
  
    return 0;  
}  



