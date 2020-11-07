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

bool mirrorCheck(Node* rootOne, Node* rootTwo){
	if(rootOne==NULL && rootTwo==NULL) return true;
	if(rootOne==NULL || rootTwo==NULL) return false;
	if(rootOne->data!= rootTwo->data) return false;

	return mirrorCheck(rootOne->left, rootTwo->right) && mirrorCheck(rootOne->right, rootTwo->left);
}

bool symmetricCheck(Node *root){
	if(root==NULL) return true;
	return mirrorCheck(root->left, root->right);
}

int main(){
	Node *root= newNode(1);
	root->left=newNode(2);
	root->right=newNode(2);
	root->left->left=newNode(3);
	root->left->right=newNode(4);
	root->right->left=newNode(4);
	root->right->right=newNode(3);
	bool ans=symmetricCheck(root);
	cout<<ans;
	cout<<endl;
}

