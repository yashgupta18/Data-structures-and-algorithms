#include <iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<cmath>
#include<utility>
#include<map>
using namespace std;

 
// Given an integer array arr, and an integer target, return the number of tuples i, j, k such that i < j < k and arr[i] + arr[j] + arr[k] == target.

// As the answer can be very large, return it modulo 109 + 7.


int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int, long> c;
        long i,j,k, count=0, n=arr.size();
        for (i = 0; i < n; ++i)
        {
            /* code */
            c[arr[i]]++;
        }
        for (auto it : c)
            for (auto it2 : c) {
                int i = it.first, j = it2.first, k = target - i - j;
                if (!c.count(k)) continue;
                if (i == j && j == k)
                    count += c[i] * (c[i] - 1) * (c[i] - 2) / 6;
                else if (i == j && j != k)
                    count += c[i] * (c[i] - 1) / 2 * c[k];
                else if (i < j && j < k)
                    count += c[i] * c[j] * c[k];
            }
        return count% int(1e9 + 7);;
    }

int main(){
	
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(5);
    cout<<threeSumMulti(arr, 8);
    return 0;



}












