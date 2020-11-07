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

void preOrder(Node* root){
	if(!root) return;
	cout<<root->data;
	preOrder(root->left);
	preOrder(root->right);
}

void invert(Node* root){
	if(!root) return;
	Node* temp=root->left;
	root->left=root->right;
	root->right=temp;
	invert(root->left);
	invert(root->right);
}

int main(){
	Node *root= newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	root->left->left=newNode(4);
	root->left->right=newNode(5);
	root->right->left=newNode(6);
	root->right->right=newNode(7);

	cout<<"Before Inversion"<<endl;
	preOrder(root);
	cout<<endl;
	cout<<"After Inversion"<<endl;
	preOrder(root);
	cout<<endl;
}

