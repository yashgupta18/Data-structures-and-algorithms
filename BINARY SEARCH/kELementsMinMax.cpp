#include<iostream>
#include<vector>
using namespace std;



// Place k elements such that minimum distance is maximized

// Given an array representing n positions along a straight line. Find k (where k <= n) elements from the array such that the maximum distance between any two (consecutive points among the k points) is maximized.

// https://www.geeksforgeeks.org/place-k-elements-such-that-minimum-distance-is-maximized/




int main()
{
    int arr[] = {1, 2, 4,8, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    cout << largestMinDist(arr, n, k);
    return 0;
}