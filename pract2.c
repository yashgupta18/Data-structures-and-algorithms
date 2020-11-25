#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;

int EvenOddSum(int input1, int input2[]) 
{ 
    int sum1 = 0; 
    int sum2 = 0; 
    for (int i = 0; i < input1; i++) { 
        if (input2[i] % 2 == 0) 
            sum1 += input2[i]; 
        else
            sum2 += input2[i]; 
    } 
    int totalSum=sum2-sum1;
    return totalSum;
} 
  
// Driver function 
int main() 
{ 
    int arr[] = { 10,11,7,12,14 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    EvenOddSum(arr, n); 
  
    return 0; 
} 