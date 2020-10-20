#include<iostream>
using namespace std;

struct Node 
{ 
    int data; 
    struct Node* left, *right; 
    Node(int data) 
    { 
        this->data = data; 
        left = right = NULL; 
    } 
}; 


int solve(Node* root, int &res){

	if(root==NULL) return 0;

	//hypothesis. gives l and r of tree
	int l=solve(root->left, res);
	int r=solve(root->right, res);

	//max of left or right subtree
	int temp=1 + max(l,r);

	//max of either temp or current node as root and l and r as subtree has biggest diameter 
	int ans=max(temp, l+r+1);

	//final result is stored in res
	res=max(res, ans);

	//return temp is for recursion part. Final ans is in res 
	// temp is for l and r recursion
	return temp;
}

  
// Driver code 
int main() 
{ 
    Node* head=NULL;
	Node* tail=NULL;
   	struct Node* root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 

  	int res=INT_MIN;
    solve(root, res);
    cout<<res; 
  
    return 0; 
} 