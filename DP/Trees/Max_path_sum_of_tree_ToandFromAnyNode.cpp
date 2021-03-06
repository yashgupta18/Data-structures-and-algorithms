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

	//inner max- max of left or right subtree 
    //outer max- max of including l and r or only current val(to not include -ve values)
	int temp=max(max(l,r) + root->data, root->data);
    
	//max of either temp or current node as root and l and r as subtree has biggest diameter 
	int ans=max(temp, l+r+root->data);

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
   	struct Node* root = new Node(-15); 
    root->left = new Node(5); 
    root->right = new Node(6); 
    root->left->left = new Node(-8); 
    root->left->right = new Node(1); 
    root->left->left->left = new Node(2); 
    root->left->left->right = new Node(6); 
    root->right->left = new Node(3); 
    root->right->right = new Node(9); 
    root->right->right->right= new Node(0); 
    root->right->right->right->left= new Node(4); 
    root->right->right->right->right= new Node(-1); 
    root->right->right->right->right->left= new Node(10); 

  	int res=INT_MIN;
    solve(root, res);
    cout<<res; 
  
    return 0; 
} 