// https://www.hackerearth.com/problem/algorithm/bfs-waali-7409c2ca-c1be890b/

// Problem
// There is an island in the form of MxN grid where each cell either has a tower built on it or is empty. Each cell is a square of unit area and each tower has a height of 1 unit.
// Monsoon has come and rain has started, The king of the island wants to estimate how much volume of water would be trapped in between the towers.
// Water will be trapped, only if it does not reach to the corner and flows out. Water from the current cell can reach to another cell only if that cell shares an edge with the current cell.

// Constraints
// 1<= MxN <= 1000000

// INPUT
// The first line will contain two integers M and N, then the following lines will contain a grid of MxN, where ''* denotes that cell is blocked and '.' denotes that it is empty.

// OUTPUT
// The output would contain the volume of water trapped.




#include <iostream>
#include<stdio.h>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<queue>
#include<string>

#include<vector>
using namespace std; 

void generatePrintBinary(int n)
{
    // Create an empty queue of strings
    queue<string> q;
 
    // Enqueue the first binary number
    q.push("1");
 
    // This loops is like BFS of a tree with 1 as root
    // 0 as left child and 1 as right child and so on
    while (n--) {
        // print the front of queue
        string s1 = q.front();
        q.pop();
        cout << s1 << "\n";
        
        string s2 = s1; // Store s1 before changing it
 
        // Append "0" to s1 and enqueue it
        q.push(s1.append("0"));
 
        // Append "1" to s2 and enqueue it. Note that s2
        // contains the previous front
        q.push(s2.append("1"));
    }
}


int main() 
{ 
    generatePrintBinary(10);
    return 0; 
}