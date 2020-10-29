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

int treeHeight(Node* root, int &diameter){
	if(root==NULL) return 0;

	int lheight=treeHeight(root->left, diameter);
	int rheight=treeHeight(root->right, diameter);

	//if sum of new heights is greater than previous diameter than update
	if(1+lheight+rheight > diameter){
		diameter=1+lheight+rheight;
	}
	//return height of l and r to root
	return 1+ max(lheight, rheight);
}


int main(){
	Node *root= newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	root->left->left=newNode(4);
	root->left->right=newNode(5);
	root->right->left=newNode(6);
	root->right->left=newNode(7);
	root->left->left->left=newNode(8);
	root->left->left->right=newNode(9);
	int diameter=0;
	treeHeight(root, diameter);
	cout<<"Diameter="<<diameter;
	return 0;
}