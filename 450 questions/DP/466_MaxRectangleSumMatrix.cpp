#include <iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<stack>
#include<map>
using namespace std; 

#define R 4
#define C 5

int kadanes(int rowSum[R]){
    int finalmax=rowSum[0];
    int currMax=rowSum[0];
    for (int i = 1; i < R; ++i)
    {
        currMax=max(currMax+rowSum[i], rowSum[i]);
        finalmax=max(finalmax, currMax);
    }

    return finalmax;
}

int findMaxSum(int M[R][C]){
    int ans=0;
    int rowSum[R];
    for (int C1 = 0; C1 < C; ++C1)
    {
        memset(rowSum, 0, sizeof(rowSum));

        for (int C2 = C1; C2 < C; ++C2)
        {
            for (int i = 0; i < R; ++i)
            {
                rowSum[i]+=M[i][C2];
            }
            ans=max(ans, kadanes(rowSum));
        }
    }
    return ans;
}


int main()  
{  
    // https://www.youtube.com/watch?v=pbajVSlZYDA&ab_channel=AnuragCodes
    int M[R][C] = { { 1,  2, -1, -4, -20 },
                    { -8, -3, 4, 2,  1 },
                    { 3,  8, 10, 1,  3 },
                    { -4, -1, 1, 7,  -6 } 
                };
 
    // Function call
    cout<<findMaxSum(M); 
}  







