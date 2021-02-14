#include <iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<stack>
#include<map>
using namespace std; 

#define R 4
#define C 5



int count(int n){
    // https://www.geeksforgeeks.org/count-number-ways-reach-given-score-game/
    // Q. Consider a game where a player can score 3 or 5 or 10 points in a move.
     // Given a total score n, find number of ways to reach the given score.

   int table[n+1];
   for(int j = 0; j < n + 1; j++) 
            table[j] = 0; 

    table[0]=1;
    for (int i = 3; i <=n; ++i)
    {
        /* code */
        table[i]+=table[i-3];
    }

    for (int i = 5; i <=n; ++i)
    {
        /* code */
        table[i]+=table[i-5];
    }

    for (int i = 10; i <=n; ++i)
    {
        /* code */
        table[i]+=table[i-10];
    }

    return table[n];
}


int main()  
{  
    int n = 20; 
    cout << "Count for " << n  << " is " << count(n) << endl; 
    return 0; 
}  







