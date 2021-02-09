#include <iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<string>
using namespace std; 

// https://www.geeksforgeeks.org/probability-of-collision-between-two-trucks/

// Function to calculate total
// number of accidents
double count_of_accident(string a,
                         string b)
{
    // String size
    int n = a.size(), m = b.size();
 
    if (n > m)
        return (m * (m + 1)) / 2;
    else
        return (n * (n + 1))
                   / 2
               + (m - n) * n;
}
 
// Function to calculate count
// of all possible collision
double count_of_collision(string a,
                          string b)
{
    int n = a.size(), m = b.size();
 
    // Stores the count of collisions
    int answer = 0;
 
    // Total number of truck in lane b
    int count_of_truck_in_lane_b = 0;
    for (int i = 0; i < m; i++)
        if (b[i] == 'T')
            count_of_truck_in_lane_b++;
 
    // Count total number of collisions
    // while traversing the string a
    for (int i = 0; i < n && i < m; i++) {
        if (a[i] == 'T')
            answer
                += count_of_truck_in_lane_b;
 
        if (b[i] == 'T')
            count_of_truck_in_lane_b--;
    }
    return answer;
}
 
// Function to calculate the
// probability of collisions
double findProbability(string a,
                       string b)
{
    // Evaluate total outcome that is
    // all the possible accident
    double total_outcome
        = count_of_accident(a, b);
 
    // Evaluate favourable outcome i.e.,
    // count of collision of trucks
    double favourable_outcome
        = count_of_collision(a, b);
 
    // Print desired probabilty
    cout << favourable_outcome
                / total_outcome;
}
 
// Driver Code
int main()
{
    string S = "TCCBCTTB", T = "BTCCBBTT";
 
    // Function Call
    findProbability(S, T);
 
    return 0;
}