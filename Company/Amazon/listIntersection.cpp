#include <iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<string>
using namespace std; 


// https://www.geeksforgeeks.org/find-all-the-intersecting-pairs-from-a-given-array/

int findIntersection(vector<pair<int, int> > v, int n){
    { 
    vector<pair<int, int> > data; 
  
    vector<vector<int> > answer(n); 
  
    // Store each pair with their positions 
    for (int i = 0; i < n; i++) { 
        data.push_back(make_pair(v[i].first, i)); 
  
        data.push_back(make_pair(v[i].second, i)); 
    } 
  
    // Sort the vector with respect to 
    // first element in the pair 
    sort(data.begin(), data.end()); 
  
    int curr = 0; 
  
    // set data structure for keeping 
    // the second element of each pair 
    set<pair<int, int> > s; 
  
    // Iterating data vector 
    for (auto it : data) { 
  
        // check if all pairs are taken 
        if (curr >= n) 
            break; 
  
        // check if current value is a second element 
        // then remove it from the set 
        if (s.count(it)) 
  
            s.erase(it); 
  
        else { 
  
            // index of the current pair 
            int i = it.second; 
  
            // Computing the second element of current pair 
            int j = v[i].second; 
  
            // Iterating in the set 
            for (auto k : s) { 
  
                // Check if the set element 
                // has higher value than the current 
                // element's second element 
                if (k.first > j) 
                    break; 
  
                int index = k.second; 
  
                answer[i].push_back(index); 
  
                answer[index].push_back(i); 
  
                curr++; 
  
                // Check if curr is equal to 
                // all available pairs or not 
                if (curr >= n) 
                    break; 
            } 
  
            // Insert second element 
            // of current pair in the set 
            s.insert(make_pair(j, i)); 
        } 
    } 
  
    // Printing the result 
    for (int i = 0; i < n; i++) { 
  
        cout << "{" << v[i].first << ", " << v[i].second << "}"
             << " is intersecting with: "; 
  
        for (int j = 0; j < answer[i].size(); j++) 
  
            cout << "{" << v[answer[i][j]].first << ", "
                 << v[answer[i][j]].second << "}"
                 << " "; 
  
        cout << "\n"; 
    } 
} 
}

// Driver Code
int main() 
{ 
  
    // initialise the size of vector 
    int n = 6; 
  
    // initialise the vector 
    vector<pair<int, int> > v; 

    v.push_back(make_pair(9,12));
    v.push_back(make_pair(2,11));
    v.push_back(make_pair(1,3));
    v.push_back(make_pair(6,10));
    v.push_back(make_pair(5,7));
    v.push_back(make_pair(4,8));
    findIntersection(v, n); 
  
    return 0; 
} 



