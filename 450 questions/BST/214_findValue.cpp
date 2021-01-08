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


Node* findVal(Node* root,int val){
	if(root==NULL || val==root->data) return root;

	if(val<root->data) {
		return findVal(root->left, val);
	}
	else{
		return findVal(root->right, val);
	}
}


int main(){
	Node *root= newNode(20);
	root->left=newNode(15);
	root->right=newNode(25);
	root->left->left=newNode(2);
	root->left->right=newNode(17);
	root->right->left=newNode(22);
	root->right->right=newNode(30);
	int val=22;
	Node* ans=findVal(root, val);
	cout<<ans->data;
}




