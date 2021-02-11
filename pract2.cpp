// C++ program to caulate height of Binary Tree 
// from InOrder and LevelOrder Traversals 
#include <iostream> 
using namespace std; 
  
/* Function to find index of value  
   in the InOrder Traversal array */
int search(int arr[], int strt, int end, int value) 
{ 
    for (int i = strt; i <= end; i++) 
        if (arr[i] == value) 
            return i; 
    return -1; 
} 
  
// Function to calculate the height 
// of the Binary Tree 
int getHeight(int in[], int level[], int start, 
              int end, int& height, int n) 
{ 
  
    // Base Case 
    if (start > end) 
        return 0; 
  
    // Get index of current root in InOrder Traversal 
    int getIndex = search(in, start, end, level[0]); 
  
    if (getIndex == -1) 
        return 0; 
  
    // Count elements in Left Subtree 
    int leftCount = getIndex - start; 
  
    // Count elements in right Subtree 
    int rightCount = end - getIndex; 
  
    // Declare two arrays for left and 
    // right subtrees 
    int* newLeftLevel = new int[leftCount]; 
    int* newRightLevel = new int[rightCount]; 
  
    int lheight = 0, rheight = 0; 
    int k = 0; 
  
    // Extract values from level order traversal array 
    // for current left subtree 
    for (int i = 0; i < n; i++) { 
        for (int j = start; j < getIndex; j++) { 
            if (level[i] == in[j]) { 
                newLeftLevel[k] = level[i]; 
                k++; 
                break; 
            } 
        } 
    } 
  
    k = 0; 
  
    // Extract values from level order traversal array 
    // for current right subtree 
    for (int i = 0; i < n; i++) { 
        for (int j = getIndex + 1; j <= end; j++) { 
            if (level[i] == in[j]) { 
                newRightLevel[k] = level[i]; 
                k++; 
                break; 
            } 
        } 
    } 
  
    // Recursively call to calculate height of left Subtree 
    if (leftCount > 0) 
        lheight = getHeight(in, newLeftLevel, start, 
                            getIndex - 1, height, leftCount); 
  
    // Recursively call to calculate height of right Subtree 
    if (rightCount > 0) 
        rheight = getHeight(in, newRightLevel, 
                            getIndex + 1, end, height, rightCount); 
  
    // Current height 
    height = max(lheight + 1, rheight + 1); 
  
    // Delete Auxiliary arrays 
    delete[] newRightLevel; 
    delete[] newLeftLevel; 
  
    // return height 
    return height; 
} 
  
// Driver program to test above functions 
int main() 
{ 
    int in[] = { 4, 2,5,1,6,3,7 }; 
    int level[] = { 1,2,3,4,5,6,7 }; 
    int n = sizeof(in) / sizeof(in[0]); 
  
    int h = 0; 
  
    cout << getHeight(in, level, 0, n - 1, h, n); 
  
    return 0; 
} 