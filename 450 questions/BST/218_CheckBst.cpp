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


bool checkBst(Node* root, int l, int r){
	if(root==NULL) return true;

	if(root->data < l || root->data > r){
		return false;
	}
	if(l>r) return false;
	return checkBst(root->left, l, root->data) && checkBst(root->right, root->data, r);


}


int main(){
	Node *root= newNode(20);
	root->left=newNode(15);
	root->right=newNode(25);
	root->left->left=newNode(2);
	root->left->right=newNode(17);
	root->right->left=newNode(22);
	root->right->right=newNode(30);
	cout<<checkBst(root,INT_MIN, INT_MAX);
	
}




