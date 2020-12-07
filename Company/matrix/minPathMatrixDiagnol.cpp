#include <iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<string>
using namespace std; 

#define R 3
#define C 3 

int minCost(int cost[R][C]){
	int T[R][C];
	for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            T[i][j] = cost[i][j];
 
            // fill first row (there is only one way to reach any cell in
            // the first row, that is from its adjacent left cell)
            if (i == 0 && j > 0)
                T[0][j] += T[0][j - 1];
 
            // fill first column (there is only one way to reach any cell
            // in the first column, that is from its adjacent top cell)
            else if (j == 0 && i > 0)
                T[i][0] += T[i - 1][0];
 
            // fill rest of the matrix (there are two way to reach any cell
            // in the rest of the matrix, that is from its adjacent left
            // cell or adjacent top cell)
            else if (i > 0 && j > 0)
                T[i][j] += min(T[i - 1][j], min(T[i][j - 1], T[i-1][j-1]));
        }
    }

	// for (int i = 1; i < R; ++i)
	// {
	// 	for(int j=1; j<C; j++){
			
	// 		cout<<"i="<<i<<" "<<"j="<<j<<"Cost[i][j]="<<cost[i][j]<<endl;
	// 	}
	// }

	cout<<endl;
	for (int i = 0; i <R; ++i)
	{
		for(int j=0; j<C; j++){
			cout<<T[i][j]<<"\t";

		}

		cout<<endl;
	}
	cout<<endl;

	return T[R-1][C-1];
}



int main()  
{  
    int cost[R][C]={  
                    {1, 2, 3},  
                    {4, 8, 2},  
                    {1, 5, 3} 
                }; 
  
   cout<<minCost(cost);  
   return 0;  
}  