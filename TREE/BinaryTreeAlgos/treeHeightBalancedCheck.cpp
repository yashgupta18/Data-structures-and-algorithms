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

// int treeHeight(Node* root){
// 	if(root==NULL) return 0;
// 	return 1+max(treeHeight(root->left), treeHeight(root->right));
// }

int treeHeight(Node* root, bool &temp){
	if(root==NULL) return 0;

	int lheight=treeHeight(root->left, temp);
	int rheight=treeHeight(root->right, temp);
	if(abs(lheight-rheight)>1) {
		temp=false;
		}
	return 1+ max(lheight, rheight);
}


int main(){
	Node *root= newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	root->left->left=newNode(4);
	root->left->right=newNode(5);
	// root->right->left=newNode(6);
	// root->right->left=newNode(7);
	bool temp=true;
	treeHeight(root, temp);
	if(temp==false){
		cout<<"Not Balanced"<<endl;
	}
	else{
		cout<<"Balanced"<<endl;
	}
	return 0;
}