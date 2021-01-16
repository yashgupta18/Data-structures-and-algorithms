#include <iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std; 

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


int LCA(Node* root, int a, int b){
	if(root==NULL) return 0;

	if(a<root->data && b<root->data){
		return LCA(root->left, a, b);
	}
	if(a>root->data && b>root->data){
		return LCA(root->right, a, b);
	} 

	return root->data;
}


int main(){
	Node *root= newNode(20);
	root->left=newNode(15);
	root->right=newNode(25);
	root->left->left=newNode(2);
	root->left->right=newNode(17);
	root->right->left=newNode(22);
	root->right->right=newNode(30);
	cout<<LCA(root,25, 30);
	// cout<<ans->data;
}




