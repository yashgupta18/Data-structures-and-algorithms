#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cstdlib>
// #include<bits/stdc++.h>


#define ll unsigned long long
using namespace std;
// Q. https://www.codechef.com/problems/PALPALS
 int mySqrt(int x) {
        if (x == 0 || x == 1)  
       return x; 
  
    // Do Binary Search for floor(sqrt(x)) 
    int start = 1, end = x, ans;    
    while (start <= end)  
    {         
        int mid = start + (end - start) / 2;

  
        // If x is a perfect square 
        if (mid*mid == x) 
            return mid; 
  
        // Since we need floor, we update answer when mid*mid is  
        // smaller than x, and move closer to sqrt(x) 
        if (mid*mid < x)  
        { 
            start = mid + 1; 
            ans = mid; 
        }  
        else // If mid*mid is greater than x 
            end = mid-1;         
    } 
    return ans; 
        
    }

int main() {
	// your code goes here
	ll a;
	cin>>a;
	cout<<mySqrt(a);
	return 0;
}

