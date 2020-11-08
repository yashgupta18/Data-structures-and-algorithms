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

void preorder(Node* root){
	if(!root) return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

int sumtree(Node* root){
	if(!root) return 0;
	int lsum=sumtree(root->left);
	int rsum=sumtree(root->right);
	
	int val = lsum+rsum+root->data;
	root->data = lsum+rsum;
	return val;
}


int main(){
	Node *root= newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	root->left->left=newNode(4);
	root->left->right=newNode(5);
	preorder(root);
	cout<<endl;
	sumtree(root);
	preorder(root);

}




