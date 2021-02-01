#include <iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<stack>
#include<map>
using namespace std; 

#define R 6
#define C 5

int printMaxSubSquare(bool M[R][C]){
    int ans[R][C];
    //initialize last row
    for (int i = R-1; i >= 0; --i)
    {
       ans[i][C-1]=M[i][C-1];
    }

    //initialize last col
    for (int i = C-1; i >= 0; --i)
    {
       ans[R-1][i]=M[R-1][i];
    }

    int maxVal=INT_MIN;

    //see right, down, dignol down to get min and update current
    for (int i = R-2; i >=0; --i)
    {
        for (int j = C-2; j >= 0; --j)
        {
            if(M[i][j]==1) {
                ans[i][j]= min(ans[i][j+1],min( ans[i+1][j], ans[i+1][j+1])) + 1; 
                if(ans[i][j]>maxVal){
                    maxVal=ans[i][j];
                }
            }
            else{
                ans[i][j]=0;
            }
        }
    }
    return maxVal;
}


int main()  
{  
    // https://www.youtube.com/watch?v=UagRoA3C5VQ&ab_channel=Pepcoding
    bool M[R][C] = {{0, 1, 1, 0, 1},  
                    {1, 1, 0, 1, 0},  
                    {0, 1, 1, 1, 0},  
                    {1, 1, 1, 1, 0},  
                    {1, 1, 1, 1, 0},  
                    {0, 0, 0, 0, 0}};  
                      
    cout<<printMaxSubSquare(M);  
}  







