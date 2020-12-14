#include <iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<stack>
using namespace std; 
  
// Q. Given a binary tree, we need to find maximum value we 
// can get by subtracting value of node B from value of node A, 
// where A and B are two nodes of the binary tree and A is an ancestor of B.
 // Expected time complexity is O(n).


struct Node{
  int data;
  Node *left, *right;
};

struct Node *newNode(int item) 
{ 
    struct Node *temp =  (struct Node *)malloc(sizeof(struct Node)); 
    temp->data = item; 
    temp->left = temp->right = NULL; 
    return temp; 
}


int maxDiff(Node *root, int &result){
	if(root==NULL) return INT_MAX;
	if (root->left == NULL && root->right == NULL) 
        return root->data; 
	
	int val=min(maxDiff(root->left, result),maxDiff(root->right,result));
	result=max(result, root->data-val);
	return min(val, root->data);
}

void inorder(Node* root) 
{ 
    if (root) 
    { 
        inorder(root->left); 
        printf("%d ", root->data); 
        inorder(root->right); 
    } 
} 

int main(){
	Node* root=newNode(8); 
    root->left = newNode(3); 
  
    root->left->left = newNode(1); 
    root->left->right = newNode(6); 
    root->left->right->left = newNode(4); 
    root->left->right->right = newNode(7); 
  
    root->right = newNode(10); 
    root->right->right = newNode(14); 
    root->right->right->left = newNode(13); 
    // inorder(root);
	int result=INT_MIN;
	maxDiff(root,result);
	cout<<result;
	return 0;
}