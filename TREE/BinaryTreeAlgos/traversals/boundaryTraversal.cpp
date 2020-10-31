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

void leftBoundary(Node* root, vector<int> &v){
	if(root==NULL) return;
	//if it is not leaf node
	if(root->left || root->right){
		v.push_back(root->data);
	}

	if(root->left){
		leftBoundary(root->left, v);
	}
	else if(root->right){
		leftBoundary(root->right, v);
	}
	return;
}

void rightBoundary(Node* root, vector<int> &v){
	if(root==NULL) return;
	//as we need last node first keep traversing recursively till last node in right direction
	if(root->right){
		rightBoundary(root->right, v);
	}
	else if(root->left){
		rightBoundary(root->left, v);
	}
	//if it is not leaf node push to vector
	if(root->left || root->right){
		v.push_back(root->data);
	}

	
	return;
}

void leafBoundary(Node* root, vector<int> &v){
	if(root==NULL) return;

	leafBoundary(root->left, v);
	//if it is leaf node
	if(!root->left && !root->right){
		v.push_back(root->data);
	}
	leafBoundary(root->right, v);
}

int main(){
	Node *root= newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	root->left->left=newNode(4);
	root->left->right=newNode(5);
	root->right->left=newNode(6);
	root->right->right=newNode(7);

	vector<int> v;
	v.push_back(root->data);
	leftBoundary(root->left,v);
	leafBoundary(root,v);
	rightBoundary(root->right,v);
	cout<<"Boundary Traversal"<<endl;
	for (int i = 0; i < v.size(); ++i)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
	return 0;
}





