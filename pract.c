#include <iostream> 
using namespace std; 
  
// Prints max at first position, min at second position 
// second max at third position, second min at fourth 
// position and so on. 
void rearrange(int arr[], int n) 
{ 
    // initialize index of first minimum and first 
    // maximum element 
    int max_ele = n-1; 
    int min_ele = 0; 
    // traverse array elements 
    for (int i = 0; i < n; i++) { 
        // at even index : we have to put maximum element 
        if (i % 2 == 0) { 
            arr[i] = arr[max_ele]; 
            max_ele -= 1; 
        } 
  
        // at odd index : we have to put minimum element 
        else { 
            arr[i] = arr[min_ele]; 
            min_ele += 1; 
        } 
    } 
} 
  
// Driver program to test above function 
int main() 
{ 
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    cout << "Original Array\n"; 
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
  
    rearrange(arr, n); 
  
    cout << "\nModified Array\n"; 
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
    return 0; 
}