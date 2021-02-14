#include <iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<stack>
#include<map>
using namespace std; 
  
// To find winner of game 
bool findWinner(int x, int y, int n) 
{ 
    // To store results 
    int dp[n + 1]; 
  
    // Initial values 
    dp[0] = false; 
    dp[1] = true; 
  
    // Computing other values. 
    for (int i = 2; i <= n; i++) { 
  
        // If A losses any of i-1 or i-x 
        // or i-y game then he will 
        // definitely win game i 
        if (i - 1 >= 0 and !dp[i - 1]) 
            dp[i] = true; 
        else if (i - x >= 0 and !dp[i - x]) 
            dp[i] = true; 
        else if (i - y >= 0 and !dp[i - y]) 
            dp[i] = true; 
  
        // Else A loses game. 
        else
            dp[i] = false; 
    } 
  
    // If dp[n] is true then A will 
    // game otherwise  he losses 
    return dp[n]; 
} 
  
// Driver program to test findWinner(); 
int main() 

// Q. A and B are playing a game. At the beginning there are n coins. 
// Given two more numbers x and y. In each move a player can pick x or y or l coins. 
// A always starts the game. The player who picks the last coin wins the game.
  // For a given value of n, find whether A will win the game or not if both are playing optimally.

// Q. https://www.geeksforgeeks.org/coin-game-winner-every-player-three-choices/
{ 
    int x = 3, y = 4, n = 5; 
    if (findWinner(x, y, n)) 
        cout << 'A'; 
    else
        cout << 'B'; 
  
    return 0; 
} 